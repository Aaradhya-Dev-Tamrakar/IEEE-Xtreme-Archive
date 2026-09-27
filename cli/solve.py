#!/usr/bin/env python3
"""
solve.py - Competitive Programming Offline Practice CLI
Part of the IEEE-Xtreme-Archive Tools Suite.

Commands:
  python cli/solve.py list [--difficulty EASY|MEDIUM|HARD|TUTORIAL] [--tag TAG] [--limit N] [--all]
  python cli/solve.py pick [--difficulty ...] [--tag ...] [--random] [--slug SLUG]
  python cli/solve.py test <solution_file> --slug <task_slug>
"""

import argparse
import difflib
import html
import json
import os
import random
import re
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

# Reconfigure stdout/stderr to utf-8 on Windows to prevent cp1252 charmap errors
if hasattr(sys.stdout, "reconfigure"):
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
        sys.stderr.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass

# Enable virtual terminal processing on Windows for ANSI colors
if sys.platform == "win32":
    os.system("")

# Base repository paths
CLI_DIR = Path(__file__).resolve().parent
REPO_ROOT = CLI_DIR.parent
TASKS_INDEX_FILE = REPO_ROOT / "ledger" / "tasks_index.json"
PLATFORMS_DIR = REPO_ROOT / "platforms"
CSACADEMY_TASKS_DIR = PLATFORMS_DIR / "csacademy" / "tasks"


class Colors:
    """ANSI color codes with automatic detection."""
    ENABLED = sys.stdout.isatty() and "NO_COLOR" not in os.environ

    RESET = "\033[0m" if ENABLED else ""
    BOLD = "\033[1m" if ENABLED else ""
    DIM = "\033[2m" if ENABLED else ""
    UNDERLINE = "\033[4m" if ENABLED else ""

    RED = "\033[91m" if ENABLED else ""
    GREEN = "\033[92m" if ENABLED else ""
    YELLOW = "\033[93m" if ENABLED else ""
    BLUE = "\033[94m" if ENABLED else ""
    MAGENTA = "\033[95m" if ENABLED else ""
    CYAN = "\033[96m" if ENABLED else ""
    WHITE = "\033[97m" if ENABLED else ""

    BG_GREEN = "\033[42;30m" if ENABLED else ""
    BG_RED = "\033[41;97m" if ENABLED else ""
    BG_YELLOW = "\033[43;30m" if ENABLED else ""
    BG_CYAN = "\033[46;30m" if ENABLED else ""

    @classmethod
    def disable(cls):
        cls.ENABLED = False
        cls.RESET = cls.BOLD = cls.DIM = cls.UNDERLINE = ""
        cls.RED = cls.GREEN = cls.YELLOW = cls.BLUE = cls.MAGENTA = cls.CYAN = cls.WHITE = ""
        cls.BG_GREEN = cls.BG_RED = cls.BG_YELLOW = cls.BG_CYAN = ""


def format_difficulty(diff: Optional[str]) -> str:
    """Format difficulty string with color badge."""
    if not diff:
        return f"{Colors.DIM}N/A{Colors.RESET}"
    diff_upper = diff.upper()
    if diff_upper == "EASY":
        return f"{Colors.GREEN}{diff_upper:<8}{Colors.RESET}"
    elif diff_upper == "MEDIUM":
        return f"{Colors.YELLOW}{diff_upper:<8}{Colors.RESET}"
    elif diff_upper == "HARD":
        return f"{Colors.RED}{diff_upper:<8}{Colors.RESET}"
    elif diff_upper == "TUTORIAL":
        return f"{Colors.CYAN}{diff_upper:<8}{Colors.RESET}"
    return f"{Colors.WHITE}{diff_upper:<8}{Colors.RESET}"


def load_tasks_index() -> List[Dict[str, Any]]:
    """Load tasks from index file, falling back to scanning disk."""
    if TASKS_INDEX_FILE.exists():
        try:
            with open(TASKS_INDEX_FILE, "r", encoding="utf-8") as f:
                tasks = json.load(f)
                return tasks
        except Exception:
            pass

    # Fallback: scan platforms/csacademy/tasks/
    tasks = []
    if CSACADEMY_TASKS_DIR.exists():
        for task_dir in sorted(CSACADEMY_TASKS_DIR.iterdir()):
            if not task_dir.is_dir():
                continue
            prob_file = task_dir / "problem.json"
            if prob_file.exists():
                try:
                    with open(prob_file, "r", encoding="utf-8") as f:
                        data = json.load(f)
                        tasks.append(data)
                        continue
                except Exception:
                    pass
            tasks.append({
                "slug": task_dir.name,
                "title": task_dir.name.replace("_", " ").replace("-", " ").title(),
                "difficulty": None,
                "contest": None,
                "solved_ratio": "N/A",
                "time_limit": "N/A",
                "memory_limit": "N/A",
            })
    return tasks


def get_task_dir(slug: str) -> Optional[Path]:
    """Find task directory across platforms."""
    csacademy_path = CSACADEMY_TASKS_DIR / slug
    if csacademy_path.exists():
        return csacademy_path
    # Search all platform directories
    if PLATFORMS_DIR.exists():
        for plat in PLATFORMS_DIR.iterdir():
            cand = plat / "tasks" / slug
            if cand.exists():
                return cand
    return None


def extract_samples_from_statement(statement_path: Path) -> List[Tuple[str, str]]:
    """
    Extract sample input/output pairs from statement.md.
    Supports standard Markdown tables with Input/Output headers and multiline cells.
    """
    if not statement_path.exists():
        return []

    try:
        content = statement_path.read_text(encoding="utf-8")
    except Exception:
        return []

    # 1. Markdown Table Parser
    lines = content.splitlines()
    header_idx = -1
    for i, line in enumerate(lines):
        if re.search(r"\|\s*Input\s*\|", line, re.I):
            header_idx = i
            break

    if header_idx != -1:
        header_line = lines[header_idx]
        headers = [c.strip().lower() for c in header_line.split("|")[1:-1]]
        inp_col = -1
        out_col = -1
        for idx, col in enumerate(headers):
            if "input" in col and inp_col == -1:
                inp_col = idx
            elif "output" in col and out_col == -1:
                out_col = idx

        if inp_col != -1 and out_col != -1:
            # Move past delimiter
            curr_idx = header_idx + 1
            while curr_idx < len(lines) and not re.search(r"\|\s*---", lines[curr_idx]):
                curr_idx += 1
            curr_idx += 1  # Skip delimiter row

            raw_rows = []
            curr_row = []
            for line in lines[curr_idx:]:
                line_str = line.strip()
                if not line_str:
                    if curr_row:
                        raw_rows.append("\n".join(curr_row))
                        curr_row = []
                    continue
                if line_str.startswith("|"):
                    if curr_row:
                        raw_rows.append("\n".join(curr_row))
                        curr_row = []
                    curr_row.append(line)
                else:
                    if curr_row:
                        curr_row.append(line)
            if curr_row:
                raw_rows.append("\n".join(curr_row))

            samples = []
            for r in raw_rows:
                cells = [c.strip() for c in r.split("|")[1:-1]]
                if len(cells) > max(inp_col, out_col):
                    def clean(val: str) -> str:
                        val = re.sub(r"<br\s*/?>", "\n", val, flags=re.I)
                        val = html.unescape(val)
                        lines_c = [l.strip() for l in val.splitlines() if l.strip()]
                        return "\n".join(lines_c)

                    inp = clean(cells[inp_col])
                    out = clean(cells[out_col])
                    if inp or out:
                        samples.append((inp, out))
            if samples:
                return samples

    # 2. Fallback: Code blocks following Sample Input / Standard input headers
    samples = []
    inp_blocks = re.findall(
        r"(?:###\s*(?:Sample|Standard)\s*input|Input:?)\s*```(?:[a-zA-Z0-9_-]*\n)?(.*?)```",
        content,
        re.DOTALL | re.I,
    )
    out_blocks = re.findall(
        r"(?:###\s*(?:Sample|Standard)\s*output|Output:?)\s*```(?:[a-zA-Z0-9_-]*\n)?(.*?)```",
        content,
        re.DOTALL | re.I,
    )
    if inp_blocks and out_blocks and len(inp_blocks) == len(out_blocks):
        for inp, out in zip(inp_blocks, out_blocks):
            samples.append((inp.strip(), out.strip()))

    return samples


def get_task_limits(task_dir: Path) -> Tuple[str, str]:
    """Retrieve time and memory limits from problem.json or statement.md."""
    prob_file = task_dir / "problem.json"
    if prob_file.exists():
        try:
            with open(prob_file, "r", encoding="utf-8") as f:
                data = json.load(f)
                return data.get("time_limit", "N/A"), data.get("memory_limit", "N/A")
        except Exception:
            pass

    stmt_file = task_dir / "statement.md"
    if stmt_file.exists():
        try:
            content = stmt_file.read_text(encoding="utf-8")
            tm = re.search(r"\*\*Time Limit:\*\*\s*`?([0-9.]+\s*[a-zA-Z]+)`?", content, re.I)
            mm = re.search(r"\*\*Memory Limit:\*\*\s*`?([0-9.]+\s*[a-zA-Z]+)`?", content, re.I)
            time_lim = tm.group(1) if tm else "N/A"
            mem_lim = mm.group(1) if mm else "N/A"
            return time_lim, mem_lim
        except Exception:
            pass
    return "N/A", "N/A"


def parse_time_limit_sec(time_lim_str: str) -> float:
    """Parse time limit string (e.g. '1000 ms', '1.5 s') to seconds."""
    if not time_lim_str or time_lim_str == "N/A":
        return 2.0
    m = re.search(r"([0-9.]+)\s*([a-zA-Z]+)?", time_lim_str)
    if not m:
        return 2.0
    val = float(m.group(1))
    unit = (m.group(2) or "ms").lower()
    if "ms" in unit:
        return val / 1000.0
    elif "s" in unit:
        return val
    return 2.0


def normalize_output(text: str) -> str:
    """Normalize output by stripping trailing whitespace per line and blank lines."""
    clean_lines = text.replace("\r\n", "\n").replace("\r", "\n").strip().split("\n")
    return "\n".join(l.rstrip() for l in clean_lines)


def get_submissions_stats(task_dir: Path) -> Dict[str, Any]:
    """Calculate statistics from archived optimal submissions."""
    idx_file = task_dir / "submissions" / "index.json"
    stats: Dict[str, Any] = {
        "count": 0,
        "best_ms": None,
        "best_user": None,
        "best_lang": None,
        "median_ms": None,
        "runtimes": [],
    }
    if not idx_file.exists():
        return stats

    try:
        with open(idx_file, "r", encoding="utf-8") as f:
            submissions = json.load(f)
    except Exception:
        return stats

    runtimes = []
    best_entry = None
    min_ms = float("inf")

    for s in submissions:
        verdict = str(s.get("verdict", ""))
        # Only look at optimal (100 points) submissions
        if "100" in verdict:
            cpu = str(s.get("cpu_time", ""))
            m = re.search(r"(\d+)\s*ms", cpu)
            if m:
                ms = int(m.group(1))
                runtimes.append(ms)
                if ms < min_ms:
                    min_ms = ms
                    best_entry = s

    stats["count"] = len(runtimes)
    if runtimes:
        runtimes.sort()
        stats["runtimes"] = runtimes
        stats["best_ms"] = min_ms
        stats["best_user"] = best_entry.get("user") if best_entry else "Anonymous"
        stats["best_lang"] = best_entry.get("language") if best_entry else "C++"
        mid = len(runtimes) // 2
        stats["median_ms"] = (runtimes[mid] if len(runtimes) % 2 != 0
                              else (runtimes[mid - 1] + runtimes[mid]) // 2)

    return stats


# ---------------------------------------------------------------------------
# CLI Command Implementations
# ---------------------------------------------------------------------------

def cmd_list(args: argparse.Namespace) -> None:
    """List matching archived tasks."""
    tasks = load_tasks_index()
    diff_filter = (args.difficulty.upper() if args.difficulty else None)
    tag_filter = (args.tag.lower() if args.tag else None)

    filtered = []
    for t in tasks:
        # Check difficulty
        t_diff = (t.get("difficulty") or "").upper()
        if diff_filter and t_diff != diff_filter:
            continue

        # Check tag
        if tag_filter:
            slug = (t.get("slug") or "").lower()
            title = (t.get("title") or "").lower()
            contest = (t.get("contest") or "").lower()
            if tag_filter not in slug and tag_filter not in title and tag_filter not in contest:
                continue

        # Check local statement availability
        t_dir = get_task_dir(t.get("slug", ""))
        has_stmt = (t_dir / "statement.md").exists() if t_dir else False
        t["_has_stmt"] = has_stmt
        filtered.append(t)

    total_matched = len(filtered)
    limit = None if args.all else (args.limit or 40)
    display_tasks = filtered[:limit] if limit else filtered

    # Print Header
    print(f"\n{Colors.BOLD}{Colors.CYAN}=== IEEE-Xtreme & CS Academy Archived Tasks ==={Colors.RESET}")
    filters_desc = []
    if diff_filter:
        filters_desc.append(f"Difficulty: {diff_filter}")
    if tag_filter:
        filters_desc.append(f"Tag: '{tag_filter}'")
    if filters_desc:
        print(f"{Colors.DIM}Filters applied: {', '.join(filters_desc)}{Colors.RESET}")
    print()

    # Table Header
    print(
        f"{Colors.BOLD}{'#':<4}  {'SLUG':<26}  {'DIFFICULTY':<10}  {'SOLVED %':<9}  {'CONTEST':<24}  {'TITLE'}{Colors.RESET}"
    )
    print(f"{Colors.DIM}{'-' * 105}{Colors.RESET}")

    for idx, t in enumerate(display_tasks, 1):
        slug = t.get("slug", "unknown")
        title = t.get("title", slug)
        if len(title) > 28:
            title = title[:25] + "..."
        contest = t.get("contest") or "-"
        if len(contest) > 23:
            contest = contest[:20] + "..."
        diff_str = format_difficulty(t.get("difficulty"))
        ratio = str(t.get("solved_ratio") or "N/A")

        # Color row if statement missing
        slug_color = Colors.WHITE if t.get("_has_stmt") else Colors.DIM

        print(
            f"{Colors.DIM}{idx:<4}{Colors.RESET}  "
            f"{slug_color}{slug:<26}{Colors.RESET}  "
            f"{diff_str}  "
            f"{Colors.WHITE}{ratio:<9}{Colors.RESET}  "
            f"{Colors.DIM}{contest:<24}{Colors.RESET}  "
            f"{Colors.BOLD}{title}{Colors.RESET}"
        )

    print(f"{Colors.DIM}{'-' * 105}{Colors.RESET}")
    if limit and total_matched > limit:
        print(
            f"{Colors.YELLOW}Showing top {limit} of {total_matched} matching tasks. "
            f"Use '--all' or '--limit {total_matched}' to view all.{Colors.RESET}"
        )
    else:
        print(f"{Colors.GREEN}Total matching tasks: {total_matched}{Colors.RESET}")

    print(
        f"\n{Colors.DIM}💡 Tip: Run 'python cli/solve.py pick --slug <slug>' or 'python cli/solve.py pick --random' to inspect a task.{Colors.RESET}\n"
    )


def cmd_pick(args: argparse.Namespace) -> None:
    """Pick a task and display its summary, limits, and statement path."""
    tasks = load_tasks_index()
    diff_filter = (args.difficulty.upper() if args.difficulty else None)
    tag_filter = (args.tag.lower() if args.tag else None)

    if args.slug:
        matching = [t for t in tasks if t.get("slug") == args.slug]
        if not matching:
            # Check if directory exists directly on disk
            t_dir = get_task_dir(args.slug)
            if t_dir:
                matching = [{
                    "slug": args.slug,
                    "title": args.slug.replace("_", " ").title(),
                    "difficulty": None,
                    "contest": None,
                    "url": f"https://csacademy.com/contest/archive/task/{args.slug}/",
                }]
            else:
                print(f"{Colors.RED}❌ Error: Task with slug '{args.slug}' not found.{Colors.RESET}")
                sys.exit(1)
    else:
        matching = []
        for t in tasks:
            t_diff = (t.get("difficulty") or "").upper()
            if diff_filter and t_diff != diff_filter:
                continue
            if tag_filter:
                slug = (t.get("slug") or "").lower()
                title = (t.get("title") or "").lower()
                contest = (t.get("contest") or "").lower()
                if tag_filter not in slug and tag_filter not in title and tag_filter not in contest:
                    continue
            matching.append(t)

        if not matching:
            print(f"{Colors.RED}❌ Error: No tasks found matching criteria.{Colors.RESET}")
            sys.exit(1)

    selected = random.choice(matching) if (args.random or not args.slug) else matching[0]
    slug = selected.get("slug", "")
    t_dir = get_task_dir(slug)
    stmt_path = t_dir / "statement.md" if t_dir else None

    time_lim, mem_lim = get_task_limits(t_dir) if t_dir else ("N/A", "N/A")
    samples = extract_samples_from_statement(stmt_path) if stmt_path else []
    sub_stats = get_submissions_stats(t_dir) if t_dir else {}

    # Print Task Card
    print(f"\n{Colors.BOLD}{Colors.CYAN}╔══════════════════════════════════════════════════════════════════════════════╗{Colors.RESET}")
    title = selected.get("title", slug)
    print(f"{Colors.BOLD}{Colors.CYAN}║  📌 TASK: {title:<67} ║{Colors.RESET}")
    print(f"{Colors.BOLD}{Colors.CYAN}╠══════════════════════════════════════════════════════════════════════════════╣{Colors.RESET}")

    diff_str = (selected.get("difficulty") or "N/A").upper()
    print(f"  {Colors.BOLD}Slug:{Colors.RESET}             {Colors.WHITE}{slug}{Colors.RESET}")
    print(f"  {Colors.BOLD}Difficulty:{Colors.RESET}       {format_difficulty(diff_str)}")
    print(f"  {Colors.BOLD}Contest:{Colors.RESET}          {selected.get('contest') or 'Standard Archive'}")
    print(f"  {Colors.BOLD}Time Limit:{Colors.RESET}       {Colors.YELLOW}{time_lim}{Colors.RESET}")
    print(f"  {Colors.BOLD}Memory Limit:{Colors.RESET}     {Colors.YELLOW}{mem_lim}{Colors.RESET}")
    if selected.get("solved_ratio"):
        print(f"  {Colors.BOLD}Solved Ratio:{Colors.RESET}     {selected.get('solved_ratio')} ({selected.get('solved_count', 0)} solved / {selected.get('tried_count', 0)} tried)")

    if stmt_path and stmt_path.exists():
        rel_stmt = stmt_path.relative_to(REPO_ROOT)
        abs_stmt = stmt_path.resolve()
        print(f"  {Colors.BOLD}Statement File:{Colors.RESET}   {Colors.GREEN}{rel_stmt}{Colors.RESET}")
        print(f"  {Colors.BOLD}File URI:{Colors.RESET}         {Colors.DIM}file:///{abs_stmt.as_posix()}{Colors.RESET}")
    else:
        print(f"  {Colors.BOLD}Statement File:{Colors.RESET}   {Colors.RED}Not found locally{Colors.RESET}")

    url = selected.get("url") or f"https://csacademy.com/contest/archive/task/{slug}/"
    print(f"  {Colors.BOLD}Web URL:{Colors.RESET}          {Colors.DIM}{url}{Colors.RESET}")

    print(f"\n  {Colors.BOLD}Samples Available:{Colors.RESET}    {Colors.GREEN}{len(samples)} sample test case(s){Colors.RESET}")
    if sub_stats.get("count", 0) > 0:
        print(
            f"  {Colors.BOLD}Archived 100pt Subs:{Colors.RESET}  {Colors.CYAN}{sub_stats['count']} solutions{Colors.RESET} "
            f"(Fastest: {Colors.BOLD}{sub_stats['best_ms']} ms{Colors.RESET} by {sub_stats['best_user']})"
        )
    print(f"{Colors.BOLD}{Colors.CYAN}╚══════════════════════════════════════════════════════════════════════════════╝{Colors.RESET}")

    # Show Sample 1 Preview if available
    if samples:
        print(f"\n{Colors.BOLD}📝 Sample #1 Preview:{Colors.RESET}")
        inp1, out1 = samples[0]
        inp_lines = inp1.splitlines()
        out_lines = out1.splitlines()

        print(f"  {Colors.DIM}Input ({len(inp_lines)} lines):{Colors.RESET}")
        for l in inp_lines[:6]:
            print(f"    {Colors.WHITE}{l}{Colors.RESET}")
        if len(inp_lines) > 6:
            print(f"    {Colors.DIM}... ({len(inp_lines) - 6} more lines){Colors.RESET}")

        print(f"  {Colors.DIM}Output ({len(out_lines)} lines):{Colors.RESET}")
        for l in out_lines[:6]:
            print(f"    {Colors.GREEN}{l}{Colors.RESET}")
        if len(out_lines) > 6:
            print(f"    {Colors.DIM}... ({len(out_lines) - 6} more lines){Colors.RESET}")

    print(f"\n{Colors.BOLD}🚀 Practice Workflow:{Colors.RESET}")
    print(f"  1. Read the problem statement: {Colors.DIM}{stmt_path}{Colors.RESET}")
    print(f"  2. Write your solution in Python ({slug}.py) or C++ ({slug}.cpp)")
    print(f"  3. Run offline test suite:     {Colors.BOLD}{Colors.CYAN}python cli/solve.py test <your_file> --slug {slug}{Colors.RESET}\n")


def detect_cxx_compiler() -> Optional[Tuple[str, str]]:
    """Detect available C++ compiler. Returns (compiler_name, path) or None."""
    # Check CXX environment variable
    cxx_env = os.environ.get("CXX")
    if cxx_env and shutil.which(cxx_env):
        return ("g++" if "g++" in cxx_env else "clang++" if "clang++" in cxx_env else "cxx", cxx_env)

    # Check g++
    gxx = shutil.which("g++")
    if gxx:
        return ("g++", gxx)

    # Check clang++
    clangxx = shutil.which("clang++")
    if clangxx:
        return ("clang++", clangxx)

    # Check MSVC cl.exe
    cl = shutil.which("cl")
    if cl:
        return ("cl", cl)

    return None


def compile_cpp(source_file: Path, output_binary: Path) -> Tuple[bool, str, float]:
    """Compile C++ solution file. Returns (success, error_message, compile_time_ms)."""
    compiler_info = detect_cxx_compiler()
    if not compiler_info:
        msg = (
            "No C++ compiler ('g++', 'clang++', or 'cl') detected in PATH.\n"
            "Please install MinGW-w64, Clang, or Visual Studio C++, or practice using Python (.py)."
        )
        return False, msg, 0.0

    comp_type, comp_path = compiler_info
    start_time = time.perf_counter()

    if comp_type in ("g++", "clang++", "cxx"):
        cmd = [comp_path, "-O2", "-std=c++20", str(source_file), "-o", str(output_binary)]
        res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if res.returncode != 0:
            # Fallback to C++17 if compiler does not support C++20
            cmd17 = [comp_path, "-O2", "-std=c++17", str(source_file), "-o", str(output_binary)]
            res17 = subprocess.run(cmd17, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            if res17.returncode == 0:
                elapsed_ms = (time.perf_counter() - start_time) * 1000
                return True, "", elapsed_ms
            elapsed_ms = (time.perf_counter() - start_time) * 1000
            return False, res.stderr or res17.stderr, elapsed_ms

    elif comp_type == "cl":
        cmd = [comp_path, "/O2", "/std:c++20", str(source_file), f"/Fe:{output_binary}", "/nologo"]
        res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if res.returncode != 0:
            elapsed_ms = (time.perf_counter() - start_time) * 1000
            return False, res.stderr or res.stdout, elapsed_ms

    elapsed_ms = (time.perf_counter() - start_time) * 1000
    return True, "", elapsed_ms


def cmd_test(args: argparse.Namespace) -> None:
    """Test a solution file against sample inputs/outputs extracted from statement.md."""
    solution_path = Path(args.solution_file).resolve()
    if not solution_path.exists():
        print(f"{Colors.RED}❌ Error: Solution file '{args.solution_file}' not found.{Colors.RESET}")
        sys.exit(1)

    # Determine slug
    slug = args.slug
    if not slug:
        # Try inferring slug from filename (e.g. addition.py -> addition)
        stem = solution_path.stem
        if get_task_dir(stem):
            slug = stem
            print(f"{Colors.DIM}Inferred task slug '{slug}' from solution filename.{Colors.RESET}")
        else:
            print(f"{Colors.RED}❌ Error: Please specify task slug using '--slug <task_slug>'.{Colors.RESET}")
            sys.exit(1)

    task_dir = get_task_dir(slug)
    if not task_dir:
        print(f"{Colors.RED}❌ Error: Task '{slug}' not found in archive directories.{Colors.RESET}")
        sys.exit(1)

    statement_path = task_dir / "statement.md"
    if not statement_path.exists():
        print(f"{Colors.RED}❌ Error: statement.md not found for task '{slug}'.{Colors.RESET}")
        sys.exit(1)

    # Extract sample input / output
    samples = extract_samples_from_statement(statement_path)
    if not samples:
        print(f"{Colors.YELLOW}⚠️  Warning: No sample input/output tables could be parsed from '{statement_path.name}'.{Colors.RESET}")
        print(f"Please inspect the problem statement manually: {statement_path}")
        sys.exit(1)

    # Determine execution strategy
    ext = solution_path.suffix.lower()
    temp_dir_obj = None
    exec_cmd: List[str] = []
    cleanup_binary = False

    time_lim_str, mem_lim_str = get_task_limits(task_dir)
    base_time_limit_sec = parse_time_limit_sec(time_lim_str)
    # Give Python a modest multiplier for runtime overhead compared to C++
    timeout_sec = (base_time_limit_sec * 3.5 if ext == ".py" else base_time_limit_sec * 2.0)
    timeout_sec = max(timeout_sec, 3.0)  # Minimum 3.0 seconds safety buffer

    print(f"\n{Colors.BOLD}{Colors.CYAN}🧪 Testing: {solution_path.name}  ⟶  Task: {slug}{Colors.RESET}")
    print(f"{Colors.DIM}Time Limit: {time_lim_str}  |  Memory Limit: {mem_lim_str}  |  Samples: {len(samples)}{Colors.RESET}")

    if ext in (".cpp", ".cc", ".cxx"):
        temp_dir_obj = tempfile.TemporaryDirectory()
        out_exe_name = "solution.exe" if sys.platform == "win32" else "solution"
        out_binary = Path(temp_dir_obj.name) / out_exe_name
        cleanup_binary = True

        print(f"{Colors.DIM}Compiling C++ solution with optimization flags (-O2 -std=c++20)...{Colors.RESET}")
        ok, err, comp_ms = compile_cpp(solution_path, out_binary)
        if not ok:
            print(f"\n{Colors.RED}{Colors.BOLD}❌ Compilation Failed!{Colors.RESET}")
            print(f"{Colors.RED}{err}{Colors.RESET}")
            if temp_dir_obj:
                temp_dir_obj.cleanup()
            sys.exit(1)
        print(f"{Colors.GREEN}✓ Compilation successful ({comp_ms:.1f} ms){Colors.RESET}\n")
        exec_cmd = [str(out_binary)]

    elif ext == ".py":
        exec_cmd = [sys.executable, str(solution_path)]
        print(f"{Colors.DIM}Interpreter: {sys.executable} (Python {sys.version.split()[0]}){Colors.RESET}\n")

    else:
        print(f"{Colors.RED}❌ Error: Unsupported solution file extension '{ext}'. (.py, .cpp, .cc supported){Colors.RESET}")
        sys.exit(1)

    # Execute tests
    all_passed = True
    execution_times_ms: List[float] = []

    for idx, (sample_in, sample_out) in enumerate(samples, 1):
        # Prepare stdin
        inp_bytes = (sample_in + "\n").encode("utf-8")
        start_time = time.perf_counter()
        status = "UNKNOWN"
        actual_output = ""
        error_msg = ""
        timed_out = False

        try:
            proc = subprocess.run(
                exec_cmd,
                input=inp_bytes,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=timeout_sec,
            )
            elapsed_ms = (time.perf_counter() - start_time) * 1000
            execution_times_ms.append(elapsed_ms)
            actual_output = proc.stdout.decode("utf-8", errors="replace")

            if proc.returncode != 0:
                status = "RTE"
                error_msg = proc.stderr.decode("utf-8", errors="replace")
            else:
                norm_actual = normalize_output(actual_output)
                norm_expected = normalize_output(sample_out)

                if norm_actual == norm_expected:
                    status = "PASS"
                else:
                    status = "FAIL"

        except subprocess.TimeoutExpired:
            elapsed_ms = timeout_sec * 1000
            execution_times_ms.append(elapsed_ms)
            status = "TLE"
            timed_out = True
        except Exception as e:
            elapsed_ms = (time.perf_counter() - start_time) * 1000
            status = "ERROR"
            error_msg = str(e)

        # Print Sample Result
        if status == "PASS":
            print(
                f"  {Colors.BG_GREEN}{Colors.BOLD} PASS {Colors.RESET} "
                f"Sample #{idx:<2}  {Colors.GREEN}{elapsed_ms:>6.1f} ms{Colors.RESET}"
            )
        elif status == "FAIL":
            all_passed = False
            print(
                f"  {Colors.BG_RED}{Colors.BOLD} FAIL {Colors.RESET} "
                f"Sample #{idx:<2}  {Colors.RED}{elapsed_ms:>6.1f} ms (Wrong Answer){Colors.RESET}"
            )
            # Display Diff
            print(f"\n    {Colors.BOLD}Input:{Colors.RESET}")
            for l in sample_in.splitlines()[:10]:
                print(f"      {Colors.DIM}{l}{Colors.RESET}")
            if len(sample_in.splitlines()) > 10:
                print(f"      {Colors.DIM}...{Colors.RESET}")

            print(f"\n    {Colors.BOLD}Expected Output:{Colors.RESET}")
            for l in sample_out.splitlines():
                print(f"      {Colors.GREEN}{l}{Colors.RESET}")

            print(f"\n    {Colors.BOLD}Actual Output:{Colors.RESET}")
            for l in actual_output.splitlines():
                print(f"      {Colors.RED}{l}{Colors.RESET}")

            # Unified Diff
            exp_lines = [l + "\n" for l in normalize_output(sample_out).split("\n")]
            act_lines = [l + "\n" for l in normalize_output(actual_output).split("\n")]
            diff = list(difflib.unified_diff(exp_lines, act_lines, fromfile="Expected", tofile="Actual"))
            if diff:
                print(f"\n    {Colors.BOLD}Diff:{Colors.RESET}")
                for d in diff:
                    d_strip = d.rstrip("\n")
                    if d.startswith("+"):
                        print(f"      {Colors.RED}{d_strip}{Colors.RESET}")
                    elif d.startswith("-"):
                        print(f"      {Colors.GREEN}{d_strip}{Colors.RESET}")
                    elif d.startswith("@"):
                        print(f"      {Colors.CYAN}{d_strip}{Colors.RESET}")
                    else:
                        print(f"      {Colors.DIM}{d_strip}{Colors.RESET}")
            print()

        elif status == "TLE":
            all_passed = False
            print(
                f"  {Colors.BG_YELLOW}{Colors.BOLD} TLE  {Colors.RESET} "
                f"Sample #{idx:<2}  {Colors.YELLOW}>{timeout_sec * 1000:.0f} ms (Time Limit Exceeded){Colors.RESET}"
            )
        elif status == "RTE":
            all_passed = False
            print(
                f"  {Colors.BG_RED}{Colors.BOLD} RTE  {Colors.RESET} "
                f"Sample #{idx:<2}  {Colors.RED}Runtime Error (Exit Code {proc.returncode}){Colors.RESET}"
            )
            if error_msg:
                print(f"    {Colors.RED}{error_msg.strip()}{Colors.RESET}")
        else:
            all_passed = False
            print(f"  {Colors.BG_RED}{Colors.BOLD} ERR  {Colors.RESET} Sample #{idx:<2}  {error_msg}")

    # Clean up temp binary
    if temp_dir_obj:
        temp_dir_obj.cleanup()

    # Archived Optimal Submissions Comparison
    sub_stats = get_submissions_stats(task_dir)
    avg_user_ms = sum(execution_times_ms) / len(execution_times_ms) if execution_times_ms else 0.0

    print(f"\n{Colors.BOLD}{Colors.CYAN}──────────────────────────────────────────────────────────────────────────────{Colors.RESET}")
    print(f"{Colors.BOLD}{Colors.CYAN}⚡ ARCHIVED BENCHMARK COMPARISON ({slug}){Colors.RESET}")
    print(f"{Colors.BOLD}{Colors.CYAN}──────────────────────────────────────────────────────────────────────────────{Colors.RESET}")

    if sub_stats.get("count", 0) > 0:
        best_str = f"{sub_stats['best_ms']} ms ({sub_stats['best_user']}, {sub_stats['best_lang']})"
        med_str = f"{sub_stats['median_ms']} ms (across {sub_stats['count']} solutions)"
        print(f"  {Colors.BOLD}Archived 100-pt Best:{Colors.RESET}    {Colors.GREEN}{best_str}{Colors.RESET}")
        print(f"  {Colors.BOLD}Archived 100-pt Median:{Colors.RESET}  {Colors.CYAN}{med_str}{Colors.RESET}")
    else:
        print(f"  {Colors.BOLD}Archived 100-pt Best:{Colors.RESET}    {Colors.DIM}No archived submissions{Colors.RESET}")

    lang_desc = f"Python {sys.version.split()[0]}" if ext == ".py" else "C++"
    print(f"  {Colors.BOLD}Your Local Sample Avg:{Colors.RESET}   {Colors.YELLOW}{avg_user_ms:.1f} ms{Colors.RESET} ({lang_desc})")

    verdict_badge = (
        f"{Colors.BG_GREEN}{Colors.BOLD} ALL SAMPLES PASSED [{len(samples)}/{len(samples)}] {Colors.RESET} ✅"
        if all_passed
        else f"{Colors.BG_RED}{Colors.BOLD} TESTS FAILED {Colors.RESET} ❌"
    )
    print(f"  {Colors.BOLD}Local Verdict:{Colors.RESET}           {verdict_badge}")
    print(f"{Colors.BOLD}{Colors.CYAN}──────────────────────────────────────────────────────────────────────────────{Colors.RESET}\n")

    sys.exit(0 if all_passed else 1)


# ---------------------------------------------------------------------------
# Argument Parsing & Entry Point
# ---------------------------------------------------------------------------

def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="python cli/solve.py",
        description="⚡ IEEE-Xtreme-Archive Offline Practice & Testing Suite",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("--no-color", action="store_true", help="Disable ANSI color output")

    subparsers = parser.add_subparsers(dest="command", help="Available subcommands")

    # Command: list
    p_list = subparsers.add_parser("list", help="List matching archived tasks")
    p_list.add_argument("--difficulty", "-d", choices=["EASY", "MEDIUM", "HARD", "TUTORIAL"],
                        type=str.upper, help="Filter by difficulty level")
    p_list.add_argument("--tag", "-t", type=str, help="Filter by keyword (in slug, title, or contest)")
    p_list.add_argument("--limit", "-l", type=int, default=40, help="Maximum tasks to display (default: 40)")
    p_list.add_argument("--all", "-a", action="store_true", help="Display all matching tasks without truncation")

    # Command: pick
    p_pick = subparsers.add_parser("pick", help="Pick an archived task to inspect and practice")
    p_pick.add_argument("--slug", "-s", type=str, help="Specific task slug to pick")
    p_pick.add_argument("--difficulty", "-d", choices=["EASY", "MEDIUM", "HARD", "TUTORIAL"],
                        type=str.upper, help="Filter candidate pool by difficulty")
    p_pick.add_argument("--tag", "-t", type=str, help="Filter candidate pool by keyword")
    p_pick.add_argument("--random", "-r", action="store_true", help="Pick a random task from matching pool")

    # Command: test
    p_test = subparsers.add_parser("test", help="Test a solution against problem sample inputs/outputs")
    p_test.add_argument("solution_file", type=str, help="Path to solution file (.py or .cpp)")
    p_test.add_argument("--slug", "-s", type=str, help="Task slug (e.g. addition, matrix_exploration)")

    return parser


def main():
    parser = build_parser()
    args = parser.parse_args()

    if args.no_color:
        Colors.disable()

    if not args.command:
        parser.print_help()
        sys.exit(0)

    if args.command == "list":
        cmd_list(args)
    elif args.command == "pick":
        cmd_pick(args)
    elif args.command == "test":
        cmd_test(args)


if __name__ == "__main__":
    main()
