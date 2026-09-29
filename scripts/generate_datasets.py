#!/usr/bin/env python3
"""
scripts/generate_datasets.py

High-performance dataset and corpus generator for IEEE-Xtreme-Archive.
Generates:
  1. datasets/cp_instruction_dataset.jsonl (Alpaca / ShareGPT compatible format)
  2. ledger/corpus.db (SQLite database with FTS5 full-text search)

Platform: Windows / Linux / macOS
Author: Aaradhya Dev Tamrakar, Antigravity Agent
"""

import argparse
import glob
import json
import os
import sqlite3
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple


DEFAULT_SYSTEM_INSTRUCTION = (
    "You are a competitive programming grandmaster. "
    "Solve the following algorithmic problem with optimal time and memory complexity."
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate instruction datasets and SQLite corpus DB from harvested CP tasks."
    )
    repo_root = Path(__file__).resolve().parent.parent
    parser.add_argument(
        "--root",
        type=Path,
        default=repo_root,
        help="Repository root directory (default: repo root).",
    )
    parser.add_argument(
        "--db-path",
        type=Path,
        default=repo_root / "ledger" / "corpus.db",
        help="Output SQLite database path (default: ledger/corpus.db).",
    )
    parser.add_argument(
        "--dataset-path",
        type=Path,
        default=repo_root / "datasets" / "cp_instruction_dataset.jsonl",
        help="Output JSONL dataset path (default: datasets/cp_instruction_dataset.jsonl).",
    )
    parser.add_argument(
        "--format",
        choices=["both", "alpaca", "sharegpt"],
        default="both",
        help="Instruction dataset format (default: 'both' supporting Alpaca and ShareGPT loaders).",
    )
    parser.add_argument(
        "--languages",
        type=str,
        default="C++,Python 3,Python",
        help="Comma-separated target languages for instruction dataset (default: 'C++,Python 3,Python').",
    )
    parser.add_argument(
        "--include-c",
        action="store_true",
        help="Include optimal C solutions in instruction dataset alongside C++ and Python.",
    )
    parser.add_argument(
        "--all-optimal",
        action="store_true",
        help="Include all verified optimal languages (C++, C, Go, Pascal, Python) in instruction dataset.",
    )
    parser.add_argument(
        "--min-verdicts",
        type=str,
        default="100 points,Accepted",
        help="Comma-separated verdicts considered verified optimal (default: '100 points,Accepted').",
    )
    parser.add_argument(
        "--skip-db",
        action="store_true",
        help="Skip generating ledger/corpus.db.",
    )
    parser.add_argument(
        "--skip-dataset",
        action="store_true",
        help="Skip generating datasets/cp_instruction_dataset.jsonl.",
    )
    parser.add_argument(
        "--quiet",
        action="store_true",
        help="Run in quiet mode with minimal output.",
    )
    return parser.parse_args()


class CorpusBuilder:
    def __init__(self, root: Path, quiet: bool = False):
        self.root = root
        self.quiet = quiet
        self.ledger_dir = self.root / "ledger"
        self.tasks_index_path = self.ledger_dir / "tasks_index.json"
        self.tasks_base_dir = self.root / "platforms" / "csacademy" / "tasks"

    def log(self, message: str) -> None:
        if not self.quiet:
            sys.stdout.write(f"[{time.strftime('%X')}] {message}\n")
            sys.stdout.flush()

    def load_master_tasks(self) -> Dict[str, Dict[str, Any]]:
        """
        Load tasks registry from tasks_index.json merged with local task directory metadata.
        """
        tasks: Dict[str, Dict[str, Any]] = {}

        if self.tasks_index_path.exists():
            with open(self.tasks_index_path, "r", encoding="utf-8") as f:
                index_list = json.load(f)
                for item in index_list:
                    slug = item.get("slug")
                    if slug:
                        tasks[slug] = {
                            "slug": slug,
                            "title": item.get("title", slug.replace("-", " ").title()),
                            "contest": item.get("contest"),
                            "difficulty": item.get("difficulty"),
                            "time_limit": None,
                            "memory_limit": None,
                            "solved_count": item.get("solved_count", 0),
                            "tried_count": item.get("tried_count", 0),
                            "statement_md": None,
                        }

        # Inspect local task directories to enrich and discover any unindexed tasks
        if self.tasks_base_dir.exists():
            for task_dir in self.tasks_base_dir.iterdir():
                if not task_dir.is_dir():
                    continue
                slug = task_dir.name
                if slug not in tasks:
                    tasks[slug] = {
                        "slug": slug,
                        "title": slug.replace("-", " ").title(),
                        "contest": None,
                        "difficulty": None,
                        "time_limit": None,
                        "memory_limit": None,
                        "solved_count": 0,
                        "tried_count": 0,
                        "statement_md": None,
                    }

                # Load problem.json if available
                prob_path = task_dir / "problem.json"
                if prob_path.exists():
                    try:
                        with open(prob_path, "r", encoding="utf-8") as f:
                            prob_data = json.load(f)
                            if prob_data.get("title"):
                                tasks[slug]["title"] = prob_data["title"]
                            if prob_data.get("contest") and not tasks[slug]["contest"]:
                                tasks[slug]["contest"] = prob_data["contest"]
                            if prob_data.get("difficulty") and not tasks[slug]["difficulty"]:
                                tasks[slug]["difficulty"] = prob_data["difficulty"]
                            if prob_data.get("time_limit"):
                                tasks[slug]["time_limit"] = prob_data["time_limit"]
                            if prob_data.get("memory_limit"):
                                tasks[slug]["memory_limit"] = prob_data["memory_limit"]
                            if prob_data.get("solved_count") is not None:
                                tasks[slug]["solved_count"] = prob_data["solved_count"]
                            if prob_data.get("tried_count") is not None:
                                tasks[slug]["tried_count"] = prob_data["tried_count"]
                    except Exception as e:
                        self.log(f"Warning: Failed to parse {prob_path}: {e}")

                # Load statement.md if available
                stmt_path = task_dir / "statement.md"
                if stmt_path.exists():
                    try:
                        with open(stmt_path, "r", encoding="utf-8", errors="replace") as f:
                            tasks[slug]["statement_md"] = f.read()
                    except Exception as e:
                        self.log(f"Warning: Failed to read {stmt_path}: {e}")

        self.log(f"Loaded {len(tasks)} master task definitions.")
        return tasks

    def load_all_submissions(self) -> List[Dict[str, Any]]:
        """
        Scan and load all submissions across all task directories.
        """
        submissions: List[Dict[str, Any]] = []
        if not self.tasks_base_dir.exists():
            return submissions

        pattern = str(self.tasks_base_dir / "*" / "submissions" / "*" / "metadata.json")
        meta_paths = glob.glob(pattern)

        for meta_str in meta_paths:
            meta_path = Path(meta_str)
            job_dir = meta_path.parent
            try:
                with open(meta_path, "r", encoding="utf-8", errors="replace") as f:
                    meta = json.load(f)

                job_id = str(meta.get("job_id", job_dir.name))
                task_slug = meta.get("task_slug", job_dir.parent.parent.name)
                user = meta.get("user")
                language = meta.get("language", "Unknown")
                verdict = meta.get("verdict", "Unknown")
                cpu_time = meta.get("cpu_time")
                memory = meta.get("memory")
                sol_filename = meta.get("solution_file")

                # Resolve solution file
                code_content = ""
                if sol_filename:
                    sol_path = job_dir / sol_filename
                    if sol_path.exists():
                        with open(sol_path, "r", encoding="utf-8", errors="replace") as sf:
                            code_content = sf.read()

                # Fallback: search for any solution.* file
                if not code_content:
                    sol_candidates = list(job_dir.glob("solution.*"))
                    if sol_candidates:
                        with open(sol_candidates[0], "r", encoding="utf-8", errors="replace") as sf:
                            code_content = sf.read()

                submissions.append(
                    {
                        "job_id": job_id,
                        "task_slug": task_slug,
                        "user": user,
                        "language": language,
                        "verdict": verdict,
                        "cpu_time": cpu_time,
                        "memory": memory,
                        "solution_code": code_content,
                    }
                )
            except Exception as e:
                self.log(f"Warning: Failed to process submission {meta_path}: {e}")

        self.log(f"Loaded {len(submissions)} submission records.")
        return submissions

    def build_sqlite_db(
        self,
        db_path: Path,
        tasks: Dict[str, Dict[str, Any]],
        submissions: List[Dict[str, Any]],
    ) -> None:
        """
        Build SQLite database with FTS5 enabled, tables 'tasks', 'submissions', and 'tasks_fts'.
        """
        t0 = time.perf_counter()
        db_path.parent.mkdir(parents=True, exist_ok=True)

        if db_path.exists():
            try:
                db_path.unlink()
            except Exception:
                pass

        conn = sqlite3.connect(str(db_path))
        cur = conn.cursor()

        # Performance pragmas
        cur.execute("PRAGMA journal_mode = WAL;")
        cur.execute("PRAGMA synchronous = NORMAL;")
        cur.execute("PRAGMA foreign_keys = ON;")

        # Create tasks table
        cur.execute(
            """
            CREATE TABLE IF NOT EXISTS tasks (
                slug TEXT PRIMARY KEY,
                title TEXT NOT NULL,
                contest TEXT,
                difficulty TEXT,
                time_limit TEXT,
                memory_limit TEXT,
                solved_count INTEGER,
                tried_count INTEGER,
                statement_md TEXT
            );
            """
        )

        # Create submissions table
        cur.execute(
            """
            CREATE TABLE IF NOT EXISTS submissions (
                job_id TEXT PRIMARY KEY,
                task_slug TEXT NOT NULL,
                user TEXT,
                language TEXT NOT NULL,
                verdict TEXT NOT NULL,
                cpu_time TEXT,
                memory TEXT,
                solution_code TEXT NOT NULL,
                FOREIGN KEY (task_slug) REFERENCES tasks(slug) ON DELETE CASCADE
            );
            """
        )

        # Create FTS5 virtual table
        cur.execute(
            """
            CREATE VIRTUAL TABLE IF NOT EXISTS tasks_fts USING fts5(
                title,
                statement_md,
                content='tasks',
                content_rowid='rowid'
            );
            """
        )

        # Triggers to keep FTS index synchronized
        cur.execute(
            """
            CREATE TRIGGER IF NOT EXISTS tasks_ai AFTER INSERT ON tasks BEGIN
                INSERT INTO tasks_fts(rowid, title, statement_md) VALUES (new.rowid, new.title, new.statement_md);
            END;
            """
        )
        cur.execute(
            """
            CREATE TRIGGER IF NOT EXISTS tasks_ad AFTER DELETE ON tasks BEGIN
                INSERT INTO tasks_fts(tasks_fts, rowid, title, statement_md) VALUES('delete', old.rowid, old.title, old.statement_md);
            END;
            """
        )
        cur.execute(
            """
            CREATE TRIGGER IF NOT EXISTS tasks_au AFTER UPDATE ON tasks BEGIN
                INSERT INTO tasks_fts(tasks_fts, rowid, title, statement_md) VALUES('delete', old.rowid, old.title, old.statement_md);
                INSERT INTO tasks_fts(rowid, title, statement_md) VALUES (new.rowid, new.title, new.statement_md);
            END;
            """
        )

        # Indexes for relational queries
        cur.execute("CREATE INDEX IF NOT EXISTS idx_submissions_task_slug ON submissions(task_slug);")
        cur.execute("CREATE INDEX IF NOT EXISTS idx_submissions_language ON submissions(language);")
        cur.execute("CREATE INDEX IF NOT EXISTS idx_submissions_verdict ON submissions(verdict);")
        cur.execute("CREATE INDEX IF NOT EXISTS idx_tasks_difficulty ON tasks(difficulty);")

        # Insert tasks in bulk
        tasks_data = [
            (
                t["slug"],
                t["title"],
                t["contest"],
                t["difficulty"],
                t["time_limit"],
                t["memory_limit"],
                t["solved_count"],
                t["tried_count"],
                t["statement_md"],
            )
            for t in tasks.values()
        ]
        cur.executemany(
            """
            INSERT OR REPLACE INTO tasks (
                slug, title, contest, difficulty, time_limit, memory_limit,
                solved_count, tried_count, statement_md
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);
            """,
            tasks_data,
        )

        # Insert submissions in bulk
        submissions_data = [
            (
                s["job_id"],
                s["task_slug"],
                s.get("user"),
                s["language"],
                s["verdict"],
                s["cpu_time"],
                s["memory"],
                s["solution_code"],
            )
            for s in submissions
        ]
        cur.executemany(
            """
            INSERT OR REPLACE INTO submissions (
                job_id, task_slug, user, language, verdict, cpu_time, memory, solution_code
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?);
            """,
            submissions_data,
        )

        # Rebuild full-text index to ensure perfect synchronization
        cur.execute("INSERT INTO tasks_fts(tasks_fts) VALUES('rebuild');")

        # Optimize SQLite database
        cur.execute("PRAGMA optimize;")
        conn.commit()
        conn.close()

        elapsed = time.perf_counter() - t0
        self.log(
            f"Built SQLite database at {db_path} ({len(tasks_data)} tasks, "
            f"{len(submissions_data)} submissions) in {elapsed:.3f}s."
        )

    def build_instruction_dataset(
        self,
        dataset_path: Path,
        tasks: Dict[str, Dict[str, Any]],
        submissions: List[Dict[str, Any]],
        target_languages: Set[str],
        valid_verdicts: Set[str],
        fmt: str = "both",
    ) -> int:
        """
        Build cp_instruction_dataset.jsonl in Alpaca / ShareGPT format.
        """
        t0 = time.perf_counter()
        dataset_path.parent.mkdir(parents=True, exist_ok=True)
        temp_path = dataset_path.with_suffix(".tmp")

        count = 0
        with open(temp_path, "w", encoding="utf-8") as out_f:
            for sub in submissions:
                task_slug = sub["task_slug"]
                language = sub["language"]
                verdict = sub["verdict"]

                # Language and verdict filter
                if language not in target_languages:
                    continue
                if verdict not in valid_verdicts:
                    continue

                task = tasks.get(task_slug)
                if not task:
                    continue

                statement_md = task.get("statement_md")
                if not statement_md or not statement_md.strip():
                    continue

                solution_code = sub.get("solution_code")
                if not solution_code or not solution_code.strip():
                    continue

                # Prepare training example
                instruction = DEFAULT_SYSTEM_INSTRUCTION
                input_text = statement_md.strip()
                output_text = solution_code.strip()

                metadata = {
                    "slug": task_slug,
                    "difficulty": task.get("difficulty"),
                    "time_limit": task.get("time_limit"),
                    "memory_limit": task.get("memory_limit"),
                    "cpu_time": sub.get("cpu_time"),
                    "memory": sub.get("memory"),
                    "language": language,
                    "job_id": sub.get("job_id"),
                    "user": sub.get("user"),
                    "solver": sub.get("user"),
                    "verdict": verdict,
                }

                record: Dict[str, Any] = {}
                if fmt in ("alpaca", "both"):
                    record["instruction"] = instruction
                    record["input"] = input_text
                    record["output"] = output_text

                if fmt in ("sharegpt", "both"):
                    record["conversations"] = [
                        {
                            "from": "human",
                            "value": f"{instruction}\n\n{input_text}",
                        },
                        {"from": "gpt", "value": output_text},
                    ]

                record["metadata"] = metadata

                out_f.write(json.dumps(record, ensure_ascii=False) + "\n")
                count += 1

        # Atomic replace
        if temp_path.exists():
            if dataset_path.exists():
                try:
                    dataset_path.unlink()
                except Exception:
                    pass
            temp_path.replace(dataset_path)

        elapsed = time.perf_counter() - t0
        self.log(
            f"Built instruction dataset at {dataset_path} ({count} examples) in {elapsed:.3f}s."
        )
        return count


def verify_outputs(db_path: Path, dataset_path: Path, quiet: bool = False) -> None:
    """
    Verify the SQLite database and instruction dataset integrity.
    """
    if not quiet:
        sys.stdout.write("\n" + "=" * 60 + "\n")
        sys.stdout.write("--- VERIFICATION & BENCHMARK REPORT ---\n")
        sys.stdout.write("=" * 60 + "\n")

    # 1. Verify JSONL Dataset
    if dataset_path.exists():
        total_lines = 0
        valid_json = 0
        sample_meta = None
        with open(dataset_path, "r", encoding="utf-8") as f:
            for line in f:
                total_lines += 1
                try:
                    obj = json.loads(line)
                    valid_json += 1
                    if sample_meta is None:
                        sample_meta = obj.get("metadata")
                except Exception as e:
                    sys.stderr.write(f"Invalid JSON at line {total_lines}: {e}\n")

        if not quiet:
            sys.stdout.write(f"[JSONL] Path: {dataset_path}\n")
            sys.stdout.write(f"[JSONL] Total Rows: {total_lines} (Valid: {valid_json}/{total_lines})\n")
            sys.stdout.write(f"[JSONL] Sample Metadata: {sample_meta}\n\n")
    else:
        if not quiet:
            sys.stdout.write(f"[JSONL] File not found: {dataset_path}\n\n")

    # 2. Verify SQLite Database
    if db_path.exists():
        conn = sqlite3.connect(str(db_path))
        cur = conn.cursor()

        tasks_count = cur.execute("SELECT count(*) FROM tasks").fetchone()[0]
        stmts_count = cur.execute("SELECT count(*) FROM tasks WHERE statement_md IS NOT NULL").fetchone()[0]
        subs_count = cur.execute("SELECT count(*) FROM submissions").fetchone()[0]
        acc_subs = cur.execute(
            "SELECT count(*) FROM submissions WHERE verdict IN ('100 points', 'Accepted')"
        ).fetchone()[0]

        # FTS5 performance query benchmark
        t0 = time.perf_counter()
        fts_res = cur.execute(
            """
            SELECT tasks.slug, tasks.title, snippet(tasks_fts, 1, '<b>', '</b>', '...', 8)
            FROM tasks_fts
            JOIN tasks ON tasks.rowid = tasks_fts.rowid
            WHERE tasks_fts MATCH 'graph OR dynamic programming OR tree'
            LIMIT 5;
            """
        ).fetchall()
        fts_time_ms = (time.perf_counter() - t0) * 1000

        # Submissions join performance query benchmark
        t1 = time.perf_counter()
        join_res = cur.execute(
            """
            SELECT t.slug, t.title, s.language, s.cpu_time, s.memory
            FROM tasks t
            JOIN submissions s ON s.task_slug = t.slug
            WHERE s.verdict = '100 points'
            ORDER BY s.cpu_time ASC
            LIMIT 5;
            """
        ).fetchall()
        join_time_ms = (time.perf_counter() - t1) * 1000

        # Schema verification
        task_cols = [c[1] for c in cur.execute("PRAGMA table_info(tasks)").fetchall()]
        sub_cols = [c[1] for c in cur.execute("PRAGMA table_info(submissions)").fetchall()]
        fts_cols = [c[1] for c in cur.execute("PRAGMA table_info(tasks_fts)").fetchall()]

        conn.close()

        if not quiet:
            sys.stdout.write(f"[SQLite] Path: {db_path}\n")
            sys.stdout.write(f"[SQLite] Tasks: {tasks_count} total ({stmts_count} with statement.md)\n")
            sys.stdout.write(f"[SQLite] Submissions: {subs_count} total ({acc_subs} verified optimal)\n")
            sys.stdout.write(f"[SQLite] Schema 'tasks': {task_cols}\n")
            sys.stdout.write(f"[SQLite] Schema 'submissions': {sub_cols}\n")
            sys.stdout.write(f"[SQLite] Schema 'tasks_fts': {fts_cols}\n")
            sys.stdout.write(f"[SQLite] FTS5 Query Benchmark ('graph OR dynamic programming OR tree'): {fts_time_ms:.2f} ms ({len(fts_res)} results)\n")
            sys.stdout.write(f"[SQLite] Relational Join Benchmark: {join_time_ms:.2f} ms\n")
            sys.stdout.write("=" * 60 + "\n")
    else:
        if not quiet:
            sys.stdout.write(f"[SQLite] DB not found: {db_path}\n")


def main() -> int:
    args = parse_args()
    builder = CorpusBuilder(root=args.root, quiet=args.quiet)

    builder.log("Starting dataset and corpus generation...")
    t_start = time.perf_counter()

    tasks = builder.load_master_tasks()
    submissions = builder.load_all_submissions()

    # Determine target languages
    target_languages: Set[str] = {lang.strip() for lang in args.languages.split(",") if lang.strip()}
    if args.include_c:
        target_languages.add("C")
    if args.all_optimal:
        target_languages.update({"C++", "C", "Python 3", "Python", "Go", "Pascal"})

    valid_verdicts: Set[str] = {v.strip() for v in args.min_verdicts.split(",") if v.strip()}

    if not args.skip_db:
        builder.build_sqlite_db(args.db_path, tasks, submissions)

    if not args.skip_dataset:
        builder.build_instruction_dataset(
            args.dataset_path,
            tasks,
            submissions,
            target_languages=target_languages,
            valid_verdicts=valid_verdicts,
            fmt=args.format,
        )

    t_total = time.perf_counter() - t_start
    builder.log(f"All operations completed in {t_total:.3f}s.")

    # Run verification suite
    verify_outputs(args.db_path, args.dataset_path, quiet=args.quiet)

    return 0


if __name__ == "__main__":
    sys.exit(main())
