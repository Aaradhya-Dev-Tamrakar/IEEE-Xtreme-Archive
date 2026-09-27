"""
CDPEngine & CDPWorkerPool: High-throughput, self-healing asynchronous Chrome DevTools Protocol engine.
Features:
- Automatic headless Chrome spawning if port 9222 is inactive
- Persistent, reusable worker tab pool (avoids tab open/close churn)
- Dynamic micro-polling (100ms) for sub-second DOM evaluation
"""

import asyncio
import json
import logging
import os
import subprocess
import time
import urllib.request
from typing import Any, Dict, List, Optional

import websockets

logger = logging.getLogger("CDPEngine")


class CDPWorker:
    def __init__(self, tab_id: str, ws_url: str, cdp_host: str = "127.0.0.1", cdp_port: int = 9222):
        self.tab_id = tab_id
        self.ws_url = ws_url
        self.cdp_host = cdp_host
        self.cdp_port = cdp_port
        self.ws: Optional[websockets.WebSocketClientProtocol] = None
        self._msg_id = 0
        self._pending_responses: Dict[int, asyncio.Future] = {}
        self._listener_task: Optional[asyncio.Task] = None

    def _is_connected(self) -> bool:
        if not self.ws:
            return False
        try:
            return self.ws.close_code is None
        except Exception:
            return False

    async def connect(self):
        if self._is_connected():
            return
        self.ws = await websockets.connect(self.ws_url, max_size=50 * 1024 * 1024)
        self._listener_task = asyncio.create_task(self._listen_loop())
        await self.send("Page.enable")
        await self.send("Runtime.enable")
        await self.send("DOM.enable")

    async def _listen_loop(self):
        try:
            while self._is_connected():
                msg = await self.ws.recv()
                data = json.loads(msg)
                msg_id = data.get("id")
                if msg_id and msg_id in self._pending_responses:
                    fut = self._pending_responses.pop(msg_id)
                    if not fut.done():
                        fut.set_result(data)
        except asyncio.CancelledError:
            pass
        except Exception as e:
            logger.debug(f"Worker {self.tab_id} CDP listener closed: {e}")

    async def send(self, method: str, params: Optional[Dict[str, Any]] = None, timeout: float = 20.0) -> Dict[str, Any]:
        if not self._is_connected():
            await self.connect()
        self._msg_id += 1
        msg_id = self._msg_id
        fut = asyncio.get_event_loop().create_future()
        self._pending_responses[msg_id] = fut
        payload = {"id": msg_id, "method": method, "params": params or {}}
        await self.ws.send(json.dumps(payload))
        try:
            return await asyncio.wait_for(fut, timeout=timeout)
        except asyncio.TimeoutError:
            self._pending_responses.pop(msg_id, None)
            raise TimeoutError(f"CDP command {method} on tab {self.tab_id} timed out after {timeout}s")

    async def evaluate(self, expression: str, timeout: float = 20.0) -> Any:
        resp = await self.send(
            "Runtime.evaluate",
            {
                "expression": expression,
                "returnByValue": True,
                "awaitPromise": True,
            },
            timeout=timeout,
        )
        res_obj = resp.get("result", {}).get("result", {})
        if res_obj.get("subtype") == "error":
            raise RuntimeError(f"JS Error: {res_obj.get('description')}")
        return res_obj.get("value")

    async def navigate(self, url: str, wait_seconds: float = 0.5):
        await self.send("Page.navigate", {"url": url})
        if wait_seconds > 0:
            await asyncio.sleep(wait_seconds)

    async def wait_for_condition(self, check_expression: str, max_wait: float = 6.0, interval: float = 0.1) -> bool:
        start = asyncio.get_event_loop().time()
        while asyncio.get_event_loop().time() - start < max_wait:
            try:
                val = await self.evaluate(check_expression, timeout=2.0)
                if val:
                    return True
            except Exception:
                pass
            await asyncio.sleep(interval)
        return False

    async def close(self):
        if self._listener_task:
            self._listener_task.cancel()
        if self._is_connected():
            await self.ws.close()


class CDPEngine:
    def __init__(self, cdp_host: str = "127.0.0.1", cdp_port: int = 9222):
        self.cdp_host = cdp_host
        self.cdp_port = cdp_port
        self.base_url = f"http://{cdp_host}:{cdp_port}"
        self.workers: List[CDPWorker] = []

    def ensure_chrome_running(self):
        try:
            urllib.request.urlopen(f"{self.base_url}/json", timeout=2)
            return
        except Exception:
            logger.info("Chrome CDP not detected on port 9222. Launching background Chrome instance...")
            user_data_dir = os.path.expanduser(r"~\.gemini\antigravity\chrome-cdp")
            chrome_path = r"C:\Program Files\Google\Chrome\Application\chrome.exe"
            args = [
                chrome_path,
                f"--remote-debugging-port={self.cdp_port}",
                f"--user-data-dir={user_data_dir}",
                "--no-first-run",
                "--no-default-browser-check",
                "about:blank",
            ]
            subprocess.Popen(args, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            
            # Poll for readiness
            for _ in range(20):
                time.sleep(0.5)
                try:
                    urllib.request.urlopen(f"{self.base_url}/json", timeout=2)
                    logger.info("Chrome CDP instance is up and responding!")
                    return
                except Exception:
                    pass
            raise RuntimeError("Failed to connect to Chrome CDP after auto-launch.")

    def _get_open_tabs(self) -> List[Dict[str, Any]]:
        self.ensure_chrome_running()
        req = urllib.request.urlopen(f"{self.base_url}/json", timeout=5)
        targets = json.loads(req.read().decode("utf-8"))
        return [t for t in targets if t.get("type") == "page" and "devtools" not in t.get("url", "")]

    def _create_tab(self) -> Dict[str, Any]:
        req = urllib.request.Request(f"{self.base_url}/json/new", method="PUT")
        res = urllib.request.urlopen(req, timeout=5).read().decode("utf-8")
        return json.loads(res)

    async def get_worker_pool(self, size: int = 6) -> List[CDPWorker]:
        self.ensure_chrome_running()
        existing_tabs = self._get_open_tabs()
        tabs = list(existing_tabs)

        while len(tabs) < size:
            new_tab = self._create_tab()
            tabs.append(new_tab)

        self.workers = []
        for t in tabs[:size]:
            worker = CDPWorker(t["id"], t["webSocketDebuggerUrl"], self.cdp_host, self.cdp_port)
            await worker.connect()
            self.workers.append(worker)

        logger.info(f"CDP Worker Pool established with {len(self.workers)} active workers.")
        return self.workers

    async def get_primary_worker(self) -> CDPWorker:
        pool = await self.get_worker_pool(size=1)
        return pool[0]

    async def close(self):
        for w in self.workers:
            await w.close()
        self.workers.clear()
