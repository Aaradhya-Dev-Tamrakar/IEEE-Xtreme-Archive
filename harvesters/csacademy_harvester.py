"""
CS Academy Autonomous Harvester: High-Throughput Optimized Parallel Archiver
Extracts problem statements, LaTeX math, leaderboard statistics, and 100-point solutions.
"""

import argparse
import asyncio
import json
import logging
import os
import re
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set

try:
    from cdp_engine import CDPEngine, CDPWorker
except ImportError:
    from harvesters.cdp_engine import CDPEngine, CDPWorker

if sys.platform == "win32":
    try:
        sys.stdout.reconfigure(encoding="utf-8")
        sys.stderr.reconfigure(encoding="utf-8")
    except Exception:
        pass

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    handlers=[logging.StreamHandler(sys.stdout)],
)
logger = logging.getLogger("CSAcademyHarvester")

BASE_DIR = Path(__file__).resolve().parent.parent
LEDGER_DIR = BASE_DIR / "ledger"
PLATFORMS_DIR = BASE_DIR / "platforms" / "csacademy"
TASKS_DIR = PLATFORMS_DIR / "tasks"

TASKS_INDEX_PATH = LEDGER_DIR / "tasks_index.json"
JOBS_QUEUE_PATH = LEDGER_DIR / "jobs_queue.json"
ARCHIVE_LEDGER_PATH = LEDGER_DIR / "archive_ledger.json"


def load_json(path: Path, default: Any = None) -> Any:
    if path.exists():
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    return default if default is not None else {}


def save_json(path: Path, data: Any):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)


def get_file_extension(language: str) -> str:
    lang = language.lower()
    if "c++" in lang or "cpp" in lang:
        return "cpp"
    if "python" in lang or "pypy" in lang:
        return "py"
    if "java" in lang:
        return "java"
    if "c#" in lang or "csharp" in lang:
        return "cs"
    if "c" in lang and "c++" not in lang:
        return "c"
    if "pascal" in lang:
        return "pas"
    if "rust" in lang:
        return "rs"
    if "go" in lang:
        return "go"
    if "javascript" in lang or "node" in lang:
        return "js"
    return "txt"


class CSAcademyHarvester:
    def __init__(self, cdp_engine: CDPEngine, concurrency: int = 6):
        self.cdp_engine = cdp_engine
        self.concurrency = concurrency
        self.tasks_index: List[Dict[str, Any]] = load_json(TASKS_INDEX_PATH, [])
        self.jobs_queue: Dict[str, Dict[str, Any]] = load_json(JOBS_QUEUE_PATH, {})
        self.ledger: Dict[str, Any] = load_json(
            ARCHIVE_LEDGER_PATH,
            {
                "completed_statements": [],
                "completed_statistics": [],
                "completed_submissions": [],
                "total_tasks_discovered": 0,
                "total_jobs_queued": 0,
                "total_jobs_archived": 0,
            },
        )
        self.lock = asyncio.Lock()

    def get_task_info(self, slug: str) -> Dict[str, Any]:
        for t in self.tasks_index:
            if t.get("slug") == slug:
                return t
        return {}

    async def discover_tasks(self, worker: CDPWorker) -> List[Dict[str, Any]]:
        logger.info("Discovering all tasks from CS Academy task archive...")
        await worker.navigate("https://csacademy.com/contest/archive/tasks/", wait_seconds=2.0)
        await worker.wait_for_condition("document.querySelector('a[href*=\"/contest/archive/task/\"]') !== null", max_wait=8.0)

        tasks_data = await worker.evaluate(
            """(() => {
                let links = Array.from(document.querySelectorAll('a[href*="/contest/archive/task/"]'));
                let seen = new Set();
                let results = [];
                
                for (let a of links) {
                    let m = a.href.match(/\\/task\\/([^\\/]+)/);
                    if (!m || seen.has(m[1])) continue;
                    seen.add(m[1]);
                    
                    let fullText = a.innerText.trim();
                    let lines = fullText.split('\\n').map(s => s.trim()).filter(Boolean);
                    let title = lines[0] || m[1];
                    
                    let contest = null;
                    let difficulty = null;
                    let ratio = null;
                    let solved = null;
                    let tried = null;
                    
                    for (let l of lines.slice(1)) {
                        if (l === 'show tags' || l === 'hide tags') continue;
                        if (['TUTORIAL', 'EASY', 'MEDIUM', 'HARD', 'EXPERT'].includes(l.toUpperCase())) {
                            difficulty = l.toUpperCase();
                        } else if (l.includes('%')) {
                            ratio = l;
                        } else if (l.includes('/')) {
                            let parts = l.split('/');
                            if (parts.length === 2 && !isNaN(parseInt(parts[0])) && !isNaN(parseInt(parts[1]))) {
                                solved = parseInt(parts[0], 10);
                                tried = parseInt(parts[1], 10);
                            }
                        } else if (!contest) {
                            contest = l;
                        }
                    }
                    
                    results.push({
                        slug: m[1],
                        title: title,
                        contest: contest,
                        difficulty: difficulty,
                        solved_ratio: ratio,
                        solved_count: solved,
                        tried_count: tried,
                        url: a.href
                    });
                }
                return results;
            })()"""
        )

        if not tasks_data:
            logger.warning("No tasks discovered. Retrying after waiting...")
            await asyncio.sleep(2)
            return await self.discover_tasks(worker)

        async with self.lock:
            self.tasks_index = tasks_data
            self.ledger["total_tasks_discovered"] = len(tasks_data)
            save_json(TASKS_INDEX_PATH, self.tasks_index)
            save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Successfully discovered and cataloged {len(tasks_data)} tasks with full metadata!")
        return tasks_data

    async def harvest_statement(self, slug: str, worker: CDPWorker) -> bool:
        task_dir = TASKS_DIR / slug
        task_dir.mkdir(parents=True, exist_ok=True)
        statement_file = task_dir / "statement.md"
        problem_file = task_dir / "problem.json"

        if statement_file.exists() and problem_file.exists() and slug in self.ledger["completed_statements"]:
            return True

        url = f"https://csacademy.com/contest/archive/task/{slug}/"
        await worker.navigate(url, wait_seconds=0.8)

        loaded = await worker.wait_for_condition(
            "document.querySelector('h1') !== null && (document.querySelector('p') !== null || document.querySelector('table') !== null)", max_wait=8.0
        )
        if not loaded:
            # Retry once with fresh navigation to survive network bursts
            await worker.navigate(url, wait_seconds=1.0)
            loaded = await worker.wait_for_condition(
                "document.querySelector('h1') !== null && (document.querySelector('p') !== null || document.querySelector('table') !== null)", max_wait=10.0
            )
            if not loaded:
                logger.warning(f"Timeout waiting for task '{slug}' to render after retry.")
                return False

        extracted = await worker.evaluate(
            """(() => {
                let h1 = document.querySelector('h1');
                if (!h1) return null;
                
                let title = h1.innerText.trim();
                let headerDiv = h1.parentElement;
                let container = headerDiv.parentElement;
                
                let limitsText = headerDiv.innerText;
                let timeLimit = (limitsText.match(/Time limit:\\s*([0-9.]+\\s*[a-zA-Z]+)/i) || [])[1] || 'N/A';
                let memoryLimit = (limitsText.match(/Memory limit:\\s*([0-9.]+\\s*[a-zA-Z]+)/i) || [])[1] || 'N/A';
                
                let clone = container.cloneNode(true);
                
                clone.querySelectorAll('.katex').forEach(el => {
                    let tex = el.querySelector('annotation[encoding="application/x-tex"]')?.textContent;
                    if (tex) {
                        let isDisplay = el.classList.contains('katex-display') || el.closest('.katex-display');
                        let rep = isDisplay ? `\\n\\n$$${tex.trim()}$$\\n\\n` : `$${tex.trim()}$`;
                        el.replaceWith(document.createTextNode(rep));
                    }
                });
                
                let cloneHeader = clone.querySelector('.text-center');
                if (cloneHeader) cloneHeader.remove();
                
                clone.querySelectorAll('table').forEach(tbl => {
                    let headers = Array.from(tbl.querySelectorAll('th')).map(th => th.innerText.trim());
                    let rows = Array.from(tbl.querySelectorAll('tbody tr, tr')).filter(r => r.querySelectorAll('td').length > 0);
                    
                    if (headers.some(h => h.toLowerCase().includes('input')) || headers.some(h => h.toLowerCase().includes('output'))) {
                        let mdTable = '\\n\\n| ' + headers.join(' | ') + ' |\\n| ' + headers.map(() => '---').join(' | ') + ' |\\n';
                        for (let r of rows) {
                            let cells = Array.from(r.querySelectorAll('td')).map(td => td.innerText.trim().replace(/\\n/g, '<br>'));
                            mdTable += '| ' + cells.join(' | ') + ' |\\n';
                        }
                        tbl.replaceWith(document.createTextNode(mdTable + '\\n'));
                    }
                });
                
                clone.querySelectorAll('h1, h2, h3, h4, h5').forEach(h => {
                    let level = h.tagName.toLowerCase() === 'h1' ? '##' : '###';
                    h.replaceWith(document.createTextNode(`\\n\\n${level} ${h.innerText.trim()}\\n\\n`));
                });
                
                clone.querySelectorAll('p').forEach(p => {
                    p.replaceWith(document.createTextNode(`\\n\\n${p.innerText.trim()}\\n\\n`));
                });
                clone.querySelectorAll('br').forEach(br => {
                    br.replaceWith(document.createTextNode('  \\n'));
                });
                
                return {
                    title: title,
                    time_limit: timeLimit,
                    memory_limit: memoryLimit,
                    content: clone.innerText.trim()
                };
            })()"""
        )

        if not extracted:
            logger.error(f"Failed to extract statement for {slug}")
            return False

        title = extracted.get("title", slug)
        time_limit = extracted.get("time_limit", "N/A")
        memory_limit = extracted.get("memory_limit", "N/A")
        content = extracted.get("content", "")

        md_content = f"# {title}\n\n"
        md_content += f"**Time Limit:** `{time_limit}`  \n"
        md_content += f"**Memory Limit:** `{memory_limit}`  \n"
        md_content += f"**Source:** [{url}]({url})  \n\n"
        md_content += "---\n\n"
        cleaned_content = re.sub(r"\n{3,}", "\n\n", content)
        md_content += cleaned_content + "\n"

        with open(statement_file, "w", encoding="utf-8") as f:
            f.write(md_content)

        task_info = self.get_task_info(slug)
        problem_metadata = {
            "slug": slug,
            "title": title,
            "contest": task_info.get("contest"),
            "difficulty": task_info.get("difficulty"),
            "time_limit": time_limit,
            "memory_limit": memory_limit,
            "solved_count": task_info.get("solved_count"),
            "tried_count": task_info.get("tried_count"),
            "solved_ratio": task_info.get("solved_ratio"),
            "url": url,
            "platform": "csacademy",
        }
        save_json(problem_file, problem_metadata)

        async with self.lock:
            if slug not in self.ledger["completed_statements"]:
                self.ledger["completed_statements"].append(slug)
                save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Saved statement for '{slug}'")
        return True

    async def harvest_statistics(self, slug: str, worker: CDPWorker) -> bool:
        task_dir = TASKS_DIR / slug
        task_dir.mkdir(parents=True, exist_ok=True)
        stats_file = task_dir / "statistics.json"

        if stats_file.exists() and slug in self.ledger["completed_statistics"]:
            return True

        url = f"https://csacademy.com/contest/archive/task/{slug}/statistics/"
        await worker.navigate(url, wait_seconds=1.0)

        # Wait until submission links load or statistics page is completely rendered
        await worker.wait_for_condition(
            "document.querySelector('a[href*=\"/submission/\"]') !== null || (!document.body.innerText.includes('Loading') && (document.body.innerText.includes('solved') || document.body.innerText.includes('No submissions') || document.querySelectorAll('table').length > 0))",
            max_wait=8.0,
            interval=0.15,
        )

        stats_data = await worker.evaluate(
            """(() => {
                let tables = Array.from(document.querySelectorAll('table'));
                let lowest_cpu = [];
                let lowest_memory = [];
                
                for (let table of tables) {
                    let headers = Array.from(table.querySelectorAll('th')).map(th => th.innerText.trim());
                    let rows = Array.from(table.querySelectorAll('tbody tr, tr')).filter(r => r.querySelectorAll('td').length > 0);
                    
                    let isCpuTable = headers.some(h => h.includes('CPU'));
                    let isMemTable = headers.some(h => h.includes('Memory'));
                    
                    for (let row of rows) {
                        let cells = Array.from(row.querySelectorAll('td')).map(td => td.innerText.trim());
                        let linkEl = row.querySelector('a[href*="/submission/"]');
                        if (!linkEl) continue;
                        
                        let jobMatch = linkEl.href.match(/\\/submission\\/(\\d+)/);
                        let jobId = jobMatch ? jobMatch[1] : null;
                        if (!jobId) continue;
                        
                        let user = cells[0] || 'Unknown';
                        let metricVal = cells[1] || '';
                        
                        let entry = {
                            job_id: jobId,
                            user: user,
                            metric: metricVal,
                            submission_url: linkEl.href
                        };
                        
                        if (isCpuTable) {
                            lowest_cpu.push(entry);
                        } else if (isMemTable) {
                            lowest_memory.push(entry);
                        }
                    }
                }
                
                return {
                    lowest_cpu: lowest_cpu,
                    lowest_memory: lowest_memory
                };
            })()"""
        )

        # Fallback to submissions feed if statistics table is empty (e.g. partial points / non-100 / archive feed)
        if not stats_data or (len(stats_data.get("lowest_cpu", [])) == 0 and len(stats_data.get("lowest_memory", [])) == 0):
            feed_url = f"https://csacademy.com/contest/archive/task/{slug}/submissions/"
            await worker.navigate(feed_url, wait_seconds=1.0)
            await worker.wait_for_condition(
                "document.querySelector('a[href*=\"/submission/\"]') !== null || !document.body.innerText.includes('Loading')",
                max_wait=6.0,
            )
            feed_data = await worker.evaluate(
                """(() => {
                    let links = Array.from(document.querySelectorAll('a[href*="/submission/"]'));
                    let submissions = [];
                    let seen = new Set();
                    for (let a of links) {
                        let m = a.href.match(/\\/submission\\/(\\d+)/);
                        if (!m || seen.has(m[1])) continue;
                        seen.add(m[1]);
                        let parent = a.closest('[class*="row"], tr, div') || a.parentElement;
                        let text = parent ? parent.innerText.replace(/\\s+/g, ' ') : '';
                        
                        let userMatch = text.match(/(?:Job\\s*#\\d+\\s+[^\\s]+\\s+[^\\s]+\\s+[^\\s]+)?\\s*([A-Za-z0-9_.-]+)\\s*--/);
                        let user = userMatch ? userMatch[1] : 'Unknown';
                        
                        submissions.push({
                            job_id: m[1],
                            user: user,
                            metric: 'feed',
                            submission_url: a.href,
                            text: text
                        });
                    }
                    
                    // Prioritize highest score (100 points / Accepted first, then partial points > 0)
                    submissions.sort((a, b) => {
                        let scoreA = (a.text.includes('100 points') || a.text.includes('Accepted')) ? 1000 : parseInt((a.text.match(/(\\d+)\\s*points/) || [])[1] || 0);
                        let scoreB = (b.text.includes('100 points') || b.text.includes('Accepted')) ? 1000 : parseInt((b.text.match(/(\\d+)\\s*points/) || [])[1] || 0);
                        return scoreB - scoreA;
                    });
                    
                    return submissions.slice(0, 20);
                })()"""
            )
            if feed_data:
                stats_data = {
                    "lowest_cpu": feed_data[:10],
                    "lowest_memory": feed_data[10:20] if len(feed_data) > 10 else feed_data[:10],
                }

        if not stats_data:
            logger.warning(f"Failed to extract statistics for {slug}")
            return False

        task_info = self.get_task_info(slug)
        stats_payload = {
            "slug": slug,
            "solvers_count": task_info.get("solved_count"),
            "tried_count": task_info.get("tried_count"),
            "solved_ratio": task_info.get("solved_ratio"),
            "lowest_cpu": stats_data.get("lowest_cpu", []),
            "lowest_memory": stats_data.get("lowest_memory", []),
        }

        save_json(stats_file, stats_payload)

        async with self.lock:
            new_jobs = 0
            for entry in stats_data.get("lowest_cpu", []) + stats_data.get("lowest_memory", []):
                job_id = entry["job_id"]
                if job_id not in self.jobs_queue:
                    self.jobs_queue[job_id] = {
                        "job_id": job_id,
                        "task_slug": slug,
                        "user": entry.get("user"),
                        "metric": entry.get("metric"),
                        "url": entry.get("submission_url", f"https://csacademy.com/submission/{job_id}"),
                        "status": "pending",
                    }
                    new_jobs += 1

            if new_jobs > 0:
                self.ledger["total_jobs_queued"] = len(self.jobs_queue)
                save_json(JOBS_QUEUE_PATH, self.jobs_queue)

            if slug not in self.ledger["completed_statistics"]:
                self.ledger["completed_statistics"].append(slug)
                save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Saved statistics for '{slug}' (Queued {new_jobs} new jobs, total queue: {len(self.jobs_queue)})")
        return True

    async def harvest_submission(self, job_id: str, worker: CDPWorker) -> bool:
        job_info = self.jobs_queue.get(job_id, {})
        slug = job_info.get("task_slug", "unknown")
        
        sub_dir = TASKS_DIR / slug / "submissions" / str(job_id)
        sub_dir.mkdir(parents=True, exist_ok=True)
        meta_file = sub_dir / "metadata.json"
        results_file = sub_dir / "results.json"

        if meta_file.exists() and results_file.exists() and job_id in self.ledger["completed_submissions"]:
            return True

        url = f"https://csacademy.com/submission/{job_id}"
        await worker.navigate(url, wait_seconds=0.5)

        await worker.wait_for_condition(
            "(document.querySelector('.ace_editor') !== null && ((window.ace && window.ace.edit(document.querySelector('.ace_editor')).getValue().length > 0) || document.querySelector('.ace_line') !== null)) || document.querySelector('table') !== null",
            max_wait=8.0,
            interval=0.15,
        )

        sub_data = await worker.evaluate(
            """(() => {
                let aceEl = document.querySelector('.ace_editor');
                let code = '';
                if (aceEl && window.ace) {
                    try {
                        code = window.ace.edit(aceEl).getValue();
                    } catch(e) {}
                }
                if (!code && aceEl && aceEl.env && aceEl.env.editor) {
                    code = aceEl.env.editor.getValue();
                }
                if (!code) {
                    code = Array.from(document.querySelectorAll('.ace_line')).map(l => l.innerText).join('\\n');
                }
                
                let pageText = document.body.innerText;
                let userMatch = pageText.match(/User:\\s*([^\\n]+)/i);
                let verdictMatch = pageText.match(/Verdict:\\s*([^\\n]+)/i);
                let langMatch = pageText.match(/Language:\\s*([^\\n]+)/i);
                let cpuMatch = pageText.match(/CPU Time usage:\\s*([^\\n]+)/i);
                let memMatch = pageText.match(/Memory usage:\\s*([^\\n]+)/i);
                let timeMatch = pageText.match(/Submission time:\\s*([^\\n]+)/i);
                
                let langBadge = document.querySelector('[class*="language"], .label-default')?.innerText.trim();
                let language = langMatch ? langMatch[1].trim() : (langBadge || 'C++');
                
                let testResults = [];
                let table = document.querySelector('table');
                if (table) {
                    let rows = Array.from(table.querySelectorAll('tbody tr, tr')).filter(r => r.querySelectorAll('td').length > 0);
                    for (let r of rows) {
                        let cells = Array.from(r.querySelectorAll('td')).map(td => td.innerText.trim());
                        if (cells.length >= 4) {
                            testResults.push({
                                test_number: cells[0],
                                cpu_usage: cells[1],
                                memory_usage: cells[2],
                                result: cells[3]
                            });
                        }
                    }
                }
                
                return {
                    code: code,
                    user: userMatch ? userMatch[1].trim() : null,
                    verdict: verdictMatch ? verdictMatch[1].trim() : null,
                    language: language,
                    cpu_time: cpuMatch ? cpuMatch[1].trim() : null,
                    memory: memMatch ? memMatch[1].trim() : null,
                    submission_time: timeMatch ? timeMatch[1].trim() : null,
                    test_results: testResults
                };
            })()"""
        )

        if not sub_data or not sub_data.get("code"):
            logger.warning(f"Failed to extract source code for submission #{job_id}")
            return False

        language = sub_data.get("language", "C++")
        ext = get_file_extension(language)
        solution_file = sub_dir / f"solution.{ext}"

        with open(solution_file, "w", encoding="utf-8") as f:
            f.write(sub_data["code"])

        metadata = {
            "job_id": job_id,
            "task_slug": slug,
            "user": sub_data.get("user") or job_info.get("user"),
            "verdict": sub_data.get("verdict", "100 points"),
            "language": language,
            "cpu_time": sub_data.get("cpu_time"),
            "memory": sub_data.get("memory"),
            "submission_time": sub_data.get("submission_time"),
            "solution_file": f"solution.{ext}",
            "url": url,
        }
        save_json(meta_file, metadata)
        save_json(results_file, sub_data.get("test_results", []))

        async with self.lock:
            sub_index_file = TASKS_DIR / slug / "submissions" / "index.json"
            sub_index = load_json(sub_index_file, [])
            if not any(s.get("job_id") == job_id for s in sub_index):
                sub_index.append(metadata)
                save_json(sub_index_file, sub_index)

            if job_id in self.jobs_queue:
                self.jobs_queue[job_id]["status"] = "archived"
                save_json(JOBS_QUEUE_PATH, self.jobs_queue)

            if job_id not in self.ledger["completed_submissions"]:
                self.ledger["completed_submissions"].append(job_id)
                self.ledger["total_jobs_archived"] = len(self.ledger["completed_submissions"])
                save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Archived submission #{job_id} ({language}, {metadata.get('cpu_time')}, {metadata.get('memory')})")
        return True

    async def run_parallel_pipeline(self, max_tasks: Optional[int] = None, specific_slug: Optional[str] = None):
        workers = await self.cdp_engine.get_worker_pool(size=self.concurrency)
        logger.info(f"Optimized CDP Worker Pool initialized with {len(workers)} persistent tabs.")

        try:
            if specific_slug:
                tasks = [{"slug": specific_slug, "title": specific_slug, "url": f"https://csacademy.com/contest/archive/task/{specific_slug}/"}]
            else:
                if not self.tasks_index:
                    await self.discover_tasks(workers[0])
                tasks = self.tasks_index

            if max_tasks:
                tasks = tasks[:max_tasks]

            pending_tasks = [t for t in tasks if t["slug"] not in self.ledger["completed_statistics"] or t["slug"] not in self.ledger["completed_statements"]]
            logger.info(f"Starting parallel processing for {len(pending_tasks)} pending tasks across {len(workers)} workers...")

            task_queue = asyncio.Queue()
            for t in pending_tasks:
                await task_queue.put(t)

            async def task_worker_loop(w_idx: int, worker: CDPWorker):
                while not task_queue.empty():
                    try:
                        task = task_queue.get_nowait()
                    except asyncio.QueueEmpty:
                        break
                    slug = task["slug"]
                    logger.info(f"[Worker {w_idx}] Processing task: {slug}")
                    try:
                        await self.harvest_statement(slug, worker)
                        await self.harvest_statistics(slug, worker)
                    except Exception as e:
                        logger.error(f"[Worker {w_idx}] Error on task {slug}: {e}")
                    finally:
                        task_queue.task_done()

            if pending_tasks:
                await asyncio.gather(*(task_worker_loop(i, w) for i, w in enumerate(workers)))

            pending_jobs = [j_id for j_id, j_data in self.jobs_queue.items() if j_data.get("status") != "archived"]
            logger.info(f"Starting parallel harvesting for {len(pending_jobs)} pending solution submissions across {len(workers)} workers...")

            job_queue = asyncio.Queue()
            for j_id in pending_jobs:
                await job_queue.put(j_id)

            t_start = time.time()
            total_jobs = len(pending_jobs)
            completed_count = 0

            async def job_worker_loop(w_idx: int, worker: CDPWorker):
                nonlocal completed_count
                while not job_queue.empty():
                    try:
                        job_id = job_queue.get_nowait()
                    except asyncio.QueueEmpty:
                        break
                    try:
                        await self.harvest_submission(job_id, worker)
                        completed_count += 1
                        if completed_count % 10 == 0 or completed_count == total_jobs:
                            elapsed = max(0.1, time.time() - t_start)
                            rate = completed_count / elapsed
                            logger.info(f"Progress: [{completed_count}/{total_jobs} jobs] - {rate:.1f} jobs/sec")
                    except Exception as e:
                        logger.error(f"[Worker {w_idx}] Error archiving submission #{job_id}: {e}")
                    finally:
                        job_queue.task_done()

            if pending_jobs:
                await asyncio.gather(*(job_worker_loop(i, w) for i, w in enumerate(workers)))

            logger.info("Parallel pipeline execution batch completed successfully!")

        finally:
            await self.cdp_engine.close()


async def main():
    parser = argparse.ArgumentParser(description="CS Academy Autonomous Parallel CP Archiver")
    parser.add_argument("--discover", action="store_true", help="Discover all tasks and save to index")
    parser.add_argument("--slug", type=str, help="Run harvester for a single task slug")
    parser.add_argument("--max-tasks", type=int, help="Limit number of tasks to process")
    parser.add_argument("--concurrency", "-c", type=int, default=6, help="Number of concurrent worker tabs (default: 6)")
    parser.add_argument("--host", type=str, default="127.0.0.1", help="CDP host")
    parser.add_argument("--port", type=int, default=9222, help="CDP port")
    args = parser.parse_args()

    cdp = CDPEngine(cdp_host=args.host, cdp_port=args.port)
    harvester = CSAcademyHarvester(cdp, concurrency=args.concurrency)

    if args.discover:
        primary = await cdp.get_primary_worker()
        await harvester.discover_tasks(primary)
        await cdp.close()
    elif args.slug:
        if args.slug in harvester.ledger["completed_statements"]:
            harvester.ledger["completed_statements"].remove(args.slug)
        if args.slug in harvester.ledger["completed_statistics"]:
            harvester.ledger["completed_statistics"].remove(args.slug)
        await harvester.run_parallel_pipeline(specific_slug=args.slug)
    else:
        await harvester.run_parallel_pipeline(max_tasks=args.max_tasks)


if __name__ == "__main__":
    asyncio.run(main())
