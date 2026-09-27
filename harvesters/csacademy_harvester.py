"""
CS Academy Autonomous Harvester: Extracts problem statements, KaTeX formulas,
leaderboard statistics, and optimal 100-point solutions into IEEE-Xtreme-Archive.
"""

import argparse
import asyncio
import json
import logging
import os
import re
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional, Set

from cdp_engine import CDPEngine

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
    def __init__(self, cdp: CDPEngine):
        self.cdp = cdp
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

    async def discover_tasks(self) -> List[Dict[str, Any]]:
        logger.info("Discovering all tasks from CS Academy task archive...")
        await self.cdp.navigate("https://csacademy.com/contest/archive/tasks/", wait_seconds=3.0)

        tasks_data = await self.cdp.evaluate(
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
            await asyncio.sleep(3)
            return await self.discover_tasks()

        self.tasks_index = tasks_data
        self.ledger["total_tasks_discovered"] = len(tasks_data)
        save_json(TASKS_INDEX_PATH, self.tasks_index)
        save_json(ARCHIVE_LEDGER_PATH, self.ledger)
        logger.info(f"Successfully discovered and cataloged {len(tasks_data)} tasks with difficulty and contest metadata!")
        return tasks_data

    def get_task_info(self, slug: str) -> Dict[str, Any]:
        for t in self.tasks_index:
            if t.get("slug") == slug:
                return t
        return {}

    async def harvest_statement(self, slug: str) -> bool:
        task_dir = TASKS_DIR / slug
        task_dir.mkdir(parents=True, exist_ok=True)
        statement_file = task_dir / "statement.md"
        problem_file = task_dir / "problem.json"

        if statement_file.exists() and problem_file.exists() and slug in self.ledger["completed_statements"]:
            return True

        url = f"https://csacademy.com/contest/archive/task/{slug}/"
        logger.info(f"Harvesting statement for task '{slug}' ({url})...")
        await self.cdp.navigate(url, wait_seconds=1.5)

        loaded = await self.cdp.wait_for_condition(
            "document.querySelector('h1') !== null", max_wait=6.0
        )
        if not loaded:
            logger.warning(f"Timeout waiting for task '{slug}' to render.")
            return False

        extracted = await self.cdp.evaluate(
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

        # Clean markdown formatting
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

        if slug not in self.ledger["completed_statements"]:
            self.ledger["completed_statements"].append(slug)
            save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Saved statement & metadata for '{slug}'")
        return True

    async def harvest_statistics(self, slug: str) -> bool:
        task_dir = TASKS_DIR / slug
        task_dir.mkdir(parents=True, exist_ok=True)
        stats_file = task_dir / "statistics.json"

        if stats_file.exists() and slug in self.ledger["completed_statistics"]:
            return True

        url = f"https://csacademy.com/contest/archive/task/{slug}/statistics/"
        logger.info(f"Harvesting statistics & leaderboard for task '{slug}' ({url})...")
        await self.cdp.navigate(url, wait_seconds=1.5)

        # Wait for submission links or tables to load asynchronously
        await self.cdp.wait_for_condition(
            "document.querySelector('a[href*=\"/submission/\"]') !== null || document.body.innerText.includes('CPU Time')",
            max_wait=6.0,
        )

        stats_data = await self.cdp.evaluate(
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

        # Queue jobs for archival
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

    async def harvest_submission(self, job_id: str) -> bool:
        job_info = self.jobs_queue.get(job_id, {})
        slug = job_info.get("task_slug", "unknown")
        
        sub_dir = TASKS_DIR / slug / "submissions" / str(job_id)
        sub_dir.mkdir(parents=True, exist_ok=True)
        meta_file = sub_dir / "metadata.json"
        results_file = sub_dir / "results.json"

        if meta_file.exists() and results_file.exists() and job_id in self.ledger["completed_submissions"]:
            return True

        url = f"https://csacademy.com/submission/{job_id}"
        logger.info(f"Harvesting submission #{job_id} for '{slug}' ({url})...")
        await self.cdp.navigate(url, wait_seconds=1.5)

        await self.cdp.wait_for_condition(
            "document.querySelector('.ace_editor') !== null || document.querySelector('table') !== null",
            max_wait=6.0,
        )

        sub_data = await self.cdp.evaluate(
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

        # Write clean original source code
        with open(solution_file, "w", encoding="utf-8") as f:
            f.write(sub_data["code"])

        # Write metadata.json
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

        # Write results.json
        save_json(results_file, sub_data.get("test_results", []))

        # Update submissions index for the task
        sub_index_file = TASKS_DIR / slug / "submissions" / "index.json"
        sub_index = load_json(sub_index_file, [])
        if not any(s.get("job_id") == job_id for s in sub_index):
            sub_index.append(metadata)
            save_json(sub_index_file, sub_index)

        # Mark job completed
        if job_id in self.jobs_queue:
            self.jobs_queue[job_id]["status"] = "archived"
            save_json(JOBS_QUEUE_PATH, self.jobs_queue)

        if job_id not in self.ledger["completed_submissions"]:
            self.ledger["completed_submissions"].append(job_id)
            self.ledger["total_jobs_archived"] = len(self.ledger["completed_submissions"])
            save_json(ARCHIVE_LEDGER_PATH, self.ledger)

        logger.info(f"Archived submission #{job_id} ({language}, {metadata.get('cpu_time')}, {metadata.get('memory')})")
        return True

    async def run_pipeline(self, max_tasks: Optional[int] = None, specific_slug: Optional[str] = None):
        if specific_slug:
            tasks = [{"slug": specific_slug, "title": specific_slug, "url": f"https://csacademy.com/contest/archive/task/{specific_slug}/"}]
        else:
            if not self.tasks_index:
                await self.discover_tasks()
            tasks = self.tasks_index

        if max_tasks:
            tasks = tasks[:max_tasks]

        logger.info(f"Starting pipeline execution for {len(tasks)} tasks...")

        # Step 1: Harvest Statements and Statistics
        for idx, task in enumerate(tasks, start=1):
            slug = task["slug"]
            logger.info(f"[{idx}/{len(tasks)}] Processing task: {slug}")
            try:
                await self.harvest_statement(slug)
                await self.harvest_statistics(slug)
            except Exception as e:
                logger.error(f"Error processing task {slug}: {e}")

        # Step 2: Harvest Submissions in Queue
        pending_jobs = [j_id for j_id, j_data in self.jobs_queue.items() if j_data.get("status") != "archived"]
        logger.info(f"Harvesting {len(pending_jobs)} pending solution submissions...")

        for idx, job_id in enumerate(pending_jobs, start=1):
            logger.info(f"[{idx}/{len(pending_jobs)}] Processing submission #{job_id}...")
            try:
                await self.harvest_submission(job_id)
            except Exception as e:
                logger.error(f"Error archiving submission #{job_id}: {e}")

        logger.info("Pipeline execution batch completed successfully!")


async def main():
    parser = argparse.ArgumentParser(description="CS Academy Autonomous CP Archiver")
    parser.add_argument("--discover", action="store_true", help="Discover all tasks and save to index")
    parser.add_argument("--slug", type=str, help="Run harvester for a single task slug")
    parser.add_argument("--max-tasks", type=int, help="Limit number of tasks to process")
    parser.add_argument("--host", type=str, default="127.0.0.1", help="CDP host")
    parser.add_argument("--port", type=int, default=9222, help="CDP port")
    args = parser.parse_args()

    cdp = CDPEngine(cdp_host=args.host, cdp_port=args.port)
    await cdp.connect()

    harvester = CSAcademyHarvester(cdp)

    try:
        if args.discover:
            await harvester.discover_tasks()
        elif args.slug:
            # Clear cache for single slug run
            if args.slug in harvester.ledger["completed_statements"]:
                harvester.ledger["completed_statements"].remove(args.slug)
            if args.slug in harvester.ledger["completed_statistics"]:
                harvester.ledger["completed_statistics"].remove(args.slug)
            await harvester.run_pipeline(specific_slug=args.slug)
        else:
            await harvester.run_pipeline(max_tasks=args.max_tasks)
    finally:
        await cdp.close()


if __name__ == "__main__":
    asyncio.run(main())
