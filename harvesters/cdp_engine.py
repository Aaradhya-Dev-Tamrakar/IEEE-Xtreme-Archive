"""
CDPEngine: Lightweight asynchronous Chrome DevTools Protocol client for CP problem & solution archival.
"""

import asyncio
import json
import logging
import urllib.request
from typing import Any, Dict, Optional

import websockets

logger = logging.getLogger("CDPEngine")


class CDPEngine:
    def __init__(self, cdp_host: str = "127.0.0.1", cdp_port: int = 9222):
        self.cdp_host = cdp_host
        self.cdp_port = cdp_port
        self.base_url = f"http://{cdp_host}:{cdp_port}"
        self.ws: Optional[websockets.WebSocketClientProtocol] = None
        self.ws_url: Optional[str] = None
        self._msg_id = 0
        self._pending_responses: Dict[int, asyncio.Future] = {}
        self._listener_task: Optional[asyncio.Task] = None

    async def get_page_ws_url(self) -> str:
        url = f"{self.base_url}/json"
        req = urllib.request.urlopen(url, timeout=5)
        targets = json.loads(req.read().decode("utf-8"))
        for target in targets:
            if target.get("type") == "page" and "devtools" not in target.get("url", ""):
                return target["webSocketDebuggerUrl"]
        # Fallback: create a new tab if no suitable page target found
        req_new = urllib.request.urlopen(f"{self.base_url}/json/new", timeout=5)
        new_target = json.loads(req_new.read().decode("utf-8"))
        return new_target["webSocketDebuggerUrl"]

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
        self.ws_url = await self.get_page_ws_url()
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
            logger.debug(f"CDP listener loop closed: {e}")

    async def send(self, method: str, params: Optional[Dict[str, Any]] = None, timeout: float = 30.0) -> Dict[str, Any]:
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
            raise TimeoutError(f"CDP command {method} timed out after {timeout}s")

    async def evaluate(self, expression: str, timeout: float = 30.0) -> Any:
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

    async def navigate(self, url: str, wait_seconds: float = 2.0):
        await self.send("Page.navigate", {"url": url})
        await asyncio.sleep(wait_seconds)

    async def wait_for_condition(self, check_expression: str, max_wait: float = 10.0, interval: float = 0.3) -> bool:
        start = asyncio.get_event_loop().time()
        while asyncio.get_event_loop().time() - start < max_wait:
            try:
                val = await self.evaluate(check_expression)
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
