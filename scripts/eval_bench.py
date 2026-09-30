#!/usr/bin/env python3
# /// script
# requires-python = ">=3.11"
# dependencies = ["google-genai>=2.3.0"]
# ///
"""
eval_bench.py — Xtreme-Bench Competitive Programming Evaluation Harness
Part of the IEEE-Xtreme-Archive Benchmark Suite.

Queries frontier LLMs on competitive programming problems from the
Xtreme-Bench corpus, validates/compiles generated code, runs it against
extracted sample test cases with strict execution timeouts, and computes
Pass@1/Pass@k metrics.

Key Capabilities:
  - Dual Language Support: C++ (compiled via g++) and Python 3 (direct execution).
  - Code Retention: Every generated solution is saved with full source code.
  - Automatic Rate-Limit Resilience: Exponential backoff with jitter and retryDelay parsing.
  - Judge-Only Mode: Grade existing JSONL run records without re-calling APIs.
  - Markdown Leaderboard: Auto-updates benchmarks/LEADERBOARD.md with rankings.

Usage:
  # Python evaluation (runs everywhere without needing g++):
  uv run scripts/eval_bench.py --language python --model gemini-3.8-flash

  # C++ evaluation (uses g++ if available, or records code for judge-only re-run):
  uv run scripts/eval_bench.py --language cpp --model gemini-3.8-flash

  # Judge an existing run file (offline grading with compiler/interpreter):
  uv run scripts/eval_bench.py --judge-only benchmarks/runs/run_xxx.jsonl

  # Single problem test:
  uv run scripts/eval_bench.py --language python --slug addition

  # Dry run (tests harness using human grandmaster solutions):
  uv run scripts/eval_bench.py --dry-run

  # Resume an interrupted run:
  uv run scripts/eval_bench.py --resume benchmarks/runs/run_xxx.jsonl
"""

import argparse
import html
import json
import math
import os
import random
import re
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
DATASET_JSONL = REPO_ROOT / "datasets" / "cp_instruction_dataset.jsonl"
TASKS_DIR = REPO_ROOT / "platforms" / "csacademy" / "tasks"
BENCHMARKS_DIR = REPO_ROOT / "benchmarks"
RUNS_DIR = BENCHMARKS_DIR / "runs"
LEADERBOARD_FILE = BENCHMARKS_DIR / "LEADERBOARD.md"

# Reconfigure stdout for Windows UTF-8
if hasattr(sys.stdout, "reconfigure"):
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
        sys.stderr.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass

# ANSI colors
if sys.platform == "win32":
    os.system("")
_TTY = sys.stdout.isatty() and "NO_COLOR" not in os.environ
C_RESET = "\033[0m" if _TTY else ""
C_BOLD = "\033[1m" if _TTY else ""
C_DIM = "\033[2m" if _TTY else ""
C_GREEN = "\033[92m" if _TTY else ""
C_RED = "\033[91m" if _TTY else ""
C_YELLOW = "\033[93m" if _TTY else ""
C_CYAN = "\033[96m" if _TTY else ""
C_MAGENTA = "\033[95m" if _TTY else ""

# ---------------------------------------------------------------------------
# System Prompts & Configurations
# ---------------------------------------------------------------------------
SYSTEM_PROMPTS = {
    "cpp": (
        "You are a competitive programming grandmaster. "
        "You will be given a problem statement with constraints, sample input/output, "
        "and time/memory limits from CS Academy or IEEEXtreme. "
        "Produce a single, complete, optimal C++ solution that reads from stdin and "
        "writes to stdout. "
        "Output ONLY the raw C++ source code — no markdown fences, no explanations, "
        "no comments about your approach. "
        "Use #include <bits/stdc++.h> and standard competitive programming conventions. "
        "Ensure the solution handles all edge cases and runs within the stated time limit."
    ),
    "python": (
        "You are a competitive programming grandmaster. "
        "You will be given a problem statement with constraints, sample input/output, "
        "and time/memory limits from CS Academy or IEEEXtreme. "
        "Produce a single, complete, optimal Python 3 solution that reads from stdin and "
        "writes to stdout using fast I/O (e.g. sys.stdin.read().split()). "
        "Output ONLY the raw Python 3 source code — no markdown fences, no explanations, "
        "no comments about your approach. "
        "Ensure the solution handles all edge cases, sets sys.setrecursionlimit if needed, "
        "and runs within the stated time and memory limits."
    ),
}

GPP_FLAGS = [
    "-std=c++17", "-O2", "-pthread",
    "-Wall", "-Wno-unused-result",
    "-DONLINE_JUDGE", "-DCS_ACADEMY",
]

EXEC_TIMEOUT_SEC = 10
API_DELAY_SEC = 15.0
MAX_RETRIES = 5


# ═══════════════════════════════════════════════════════════════════════════
# Sample Test Case Extraction
# ═══════════════════════════════════════════════════════════════════════════

def extract_sample_tests(markdown_content: str) -> List[Tuple[str, str]]:
    """
    Extract (stdin, expected_stdout) pairs from CS Academy problem statements.
    Handles <br>/<br/> tags for multi-line values inside markdown tables.
    """
    lines = markdown_content.splitlines()
    table_lines: List[str] = []
    in_table = False

    for line in lines:
        if re.search(r'\|\s*Input\s*\|\s*Output', line, re.IGNORECASE):
            in_table = True
            table_lines = [line]
        elif in_table:
            stripped = line.strip()
            if stripped.startswith('|'):
                table_lines.append(line)
            elif stripped == '':
                continue
            else:
                break

    samples: List[Tuple[str, str]] = []
    if len(table_lines) >= 3:
        for row in table_lines[2:]:
            raw_cols = row.split('|')
            raw_cols = raw_cols[1:-1] if len(raw_cols) > 2 else raw_cols
            if len(raw_cols) >= 2:
                stdin_val = raw_cols[0].strip()
                stdout_val = raw_cols[1].strip()

                stdin_val = re.sub(r'<br\s*/?>', '\n', stdin_val)
                stdout_val = re.sub(r'<br\s*/?>', '\n', stdout_val)

                stdin_val = html.unescape(stdin_val)
                stdout_val = html.unescape(stdout_val)

                stdin_val = re.sub(r'^\$(.+)\$$', r'\1', stdin_val.strip())
                stdout_val = re.sub(r'^\$(.+)\$$', r'\1', stdout_val.strip())

                if stdin_val.strip() and stdout_val.strip():
                    samples.append((
                        stdin_val.strip() + '\n',
                        stdout_val.strip() + '\n',
                    ))
    return samples


# ═══════════════════════════════════════════════════════════════════════════
# Code Extraction from LLM Response
# ═══════════════════════════════════════════════════════════════════════════

def extract_code(response_text: str, language: str = "cpp") -> str:
    """Extract code from LLM response for C++ or Python."""
    if not response_text:
        return ""

    if language == "python":
        patterns = [
            r'```(?:python|python3|py)\s*\n(.*?)```',
            r'```\s*\n(.*?)```',
        ]
        for pattern in patterns:
            match = re.search(pattern, response_text, re.DOTALL)
            if match:
                return match.group(1).strip()
        text = response_text.strip()
        if text.startswith("import ") or text.startswith("from ") or text.startswith("def ") or text.startswith("#"):
            return text
        return text
    else:
        # C++
        patterns = [
            r'```(?:cpp|c\+\+|C\+\+)\s*\n(.*?)```',
            r'```\s*\n(.*?)```',
        ]
        for pattern in patterns:
            match = re.search(pattern, response_text, re.DOTALL)
            if match:
                return match.group(1).strip()

        text = response_text.strip()
        if text.startswith('#include') or text.startswith('//') or text.startswith('using '):
            return text

        idx = text.find('#include')
        if idx >= 0:
            return text[idx:].strip()

        return text


# ═══════════════════════════════════════════════════════════════════════════
# Compilation & Execution
# ═══════════════════════════════════════════════════════════════════════════

def find_compiler() -> Optional[str]:
    """Find a C++ compiler in PATH."""
    for compiler in ['g++', 'g++-14', 'g++-13', 'g++-12', 'clang++', 'c++']:
        path = shutil.which(compiler)
        if path:
            return path
    return None


def validate_and_compile(
    source_code: str,
    language: str,
    compiler: Optional[str],
    tmpdir: str,
) -> Tuple[bool, str, str]:
    """
    Validate syntax / compile source code.
    Returns (success, executable_or_script_path, error_msg).
    """
    if language == "python":
        src_path = os.path.join(tmpdir, "solution.py")
        with open(src_path, 'w', encoding='utf-8') as f:
            f.write(source_code)
        try:
            compile(source_code, "solution.py", "exec")
            return True, src_path, ""
        except SyntaxError as e:
            return False, "", f"SyntaxError: line {e.lineno}: {e.msg}"
        except Exception as e:
            return False, "", str(e)

    # C++
    if not compiler:
        return False, "", "no_compiler"

    src_path = os.path.join(tmpdir, "solution.cpp")
    exe_path = os.path.join(tmpdir, "solution.exe" if sys.platform == "win32" else "solution")

    with open(src_path, 'w', encoding='utf-8') as f:
        f.write(source_code)

    cmd = [compiler] + GPP_FLAGS + [src_path, "-o", exe_path]
    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=30,
            cwd=tmpdir,
        )
        if result.returncode == 0:
            return True, exe_path, ""
        else:
            return False, "", result.stderr[:2000]
    except subprocess.TimeoutExpired:
        return False, "", "Compilation timed out (30s)"
    except Exception as e:
        return False, "", str(e)


def run_solution(
    target_path: str,
    stdin_data: str,
    timeout_sec: float = EXEC_TIMEOUT_SEC,
    language: str = "cpp",
) -> Tuple[str, float, bool, str]:
    """Run compiled solution or Python script against stdin."""
    try:
        cmd = [sys.executable, target_path] if language == "python" else [target_path]
        start = time.perf_counter()
        result = subprocess.run(
            cmd,
            input=stdin_data,
            capture_output=True,
            text=True,
            timeout=timeout_sec,
        )
        elapsed = time.perf_counter() - start
        if result.returncode != 0:
            return "", elapsed, False, f"Runtime error (exit code {result.returncode}): {result.stderr[:500]}"
        return result.stdout, elapsed, False, ""
    except subprocess.TimeoutExpired:
        elapsed = timeout_sec
        return "", elapsed, True, f"Time limit exceeded ({timeout_sec}s)"
    except Exception as e:
        return "", 0.0, False, str(e)


def judge_output(actual: str, expected: str) -> bool:
    """Compare actual output with expected, tolerant of trailing whitespace."""
    actual_lines = [line.rstrip() for line in actual.strip().splitlines()]
    expected_lines = [line.rstrip() for line in expected.strip().splitlines()]
    return actual_lines == expected_lines


# ═══════════════════════════════════════════════════════════════════════════
# Problem Loading
# ═══════════════════════════════════════════════════════════════════════════

def load_unique_problems() -> List[Dict[str, Any]]:
    """Load one representative entry per unique slug from the dataset."""
    seen_slugs: set = set()
    problems: List[Dict[str, Any]] = []

    with open(DATASET_JSONL, encoding='utf-8') as f:
        for line in f:
            entry = json.loads(line)
            slug = entry['metadata']['slug']
            if slug in seen_slugs:
                continue
            seen_slugs.add(slug)

            statement = entry['input']
            samples = extract_sample_tests(statement)

            if not samples:
                stmt_path = TASKS_DIR / slug / "statement.md"
                if stmt_path.exists():
                    disk_stmt = stmt_path.read_text(encoding='utf-8', errors='replace')
                    samples = extract_sample_tests(disk_stmt)

            problems.append({
                'slug': slug,
                'title': slug.replace('-', ' ').replace('_', ' ').title(),
                'difficulty': entry['metadata'].get('difficulty'),
                'time_limit': entry['metadata'].get('time_limit', '1000 ms'),
                'memory_limit': entry['metadata'].get('memory_limit', '256 MB'),
                'statement': statement,
                'samples': samples,
                'human_solutions_count': 0,
            })

    slug_counts: Dict[str, int] = {}
    with open(DATASET_JSONL, encoding='utf-8') as f:
        for line in f:
            entry = json.loads(line)
            s = entry['metadata']['slug']
            slug_counts[s] = slug_counts.get(s, 0) + 1
    for p in problems:
        p['human_solutions_count'] = slug_counts.get(p['slug'], 0)

    return problems


def parse_time_limit_ms(tl_str: str) -> float:
    match = re.search(r'(\d+(?:\.\d+)?)\s*(?:ms|milliseconds?)', tl_str, re.IGNORECASE)
    if match:
        return float(match.group(1)) / 1000.0
    match = re.search(r'(\d+(?:\.\d+)?)\s*(?:s|seconds?)', tl_str, re.IGNORECASE)
    if match:
        return float(match.group(1))
    return 10.0


# ═══════════════════════════════════════════════════════════════════════════
# LLM Query with Rate-Limit Backoff
# ═══════════════════════════════════════════════════════════════════════════

def query_gemini(
    client: Any,
    model: str,
    problem_statement: str,
    language: str = "cpp",
    temperature: float = 1.0,
) -> Tuple[str, Dict[str, Any]]:
    """Query Gemini model for a competitive programming solution."""
    from google.genai import types

    sys_instruction = SYSTEM_PROMPTS.get(language, SYSTEM_PROMPTS["cpp"])
    config = types.GenerateContentConfig(
        system_instruction=sys_instruction,
        temperature=temperature,
        max_output_tokens=8192,
    )

    last_err = None
    for attempt in range(MAX_RETRIES + 1):
        try:
            response = client.models.generate_content(
                model=model,
                contents=problem_statement,
                config=config,
            )

            usage = {}
            if hasattr(response, 'usage_metadata') and response.usage_metadata:
                um = response.usage_metadata
                usage = {
                    'prompt_tokens': getattr(um, 'prompt_token_count', 0),
                    'output_tokens': getattr(um, 'candidates_token_count', 0)
                                     or getattr(um, 'total_token_count', 0),
                }

            return response.text or "", usage

        except Exception as e:
            last_err = e
            err_str = str(e)
            is_retryable = ('429' in err_str or 'RESOURCE_EXHAUSTED' in err_str
                            or '503' in err_str or '500' in err_str)
            if not is_retryable or attempt >= MAX_RETRIES:
                raise

            wait = min(60.0, (2 ** attempt) * 2.0) + random.uniform(0, 2)
            retry_match = re.search(r'retryDelay.*?(\d+(?:\.\d+)?)\s*s', err_str)
            if retry_match:
                wait = max(wait, float(retry_match.group(1)) + 1.0)

            print(f"    {C_YELLOW}↻{C_RESET} Rate limited, "
                  f"retry {attempt + 1}/{MAX_RETRIES} in {wait:.0f}s…")
            time.sleep(wait)

    raise last_err  # type: ignore[misc]


# ═══════════════════════════════════════════════════════════════════════════
# Pass@k Computation
# ═══════════════════════════════════════════════════════════════════════════

def pass_at_k(n: int, c: int, k: int) -> float:
    if n - c < k:
        return 1.0
    return 1.0 - math.prod(range(n - c - k + 1, n - c + 1)) / math.prod(range(n - k + 1, n + 1))


# ═══════════════════════════════════════════════════════════════════════════
# Result Types
# ═══════════════════════════════════════════════════════════════════════════

class SampleResult:
    """Result of evaluating one sample on one problem."""

    def __init__(self, slug: str, sample_idx: int, language: str = "cpp"):
        self.slug = slug
        self.sample_idx = sample_idx
        self.language = language
        self.code: str = ""
        self.compiled: bool = False
        self.compile_error: str = ""
        self.test_results: List[Dict] = []
        self.all_tests_passed: bool = False
        self.response_text: str = ""
        self.usage: Dict = {}
        self.query_time_sec: float = 0.0
        self.error: str = ""

    def to_dict(self) -> Dict:
        return {
            'slug': self.slug,
            'sample_idx': self.sample_idx,
            'language': self.language,
            'code': self.code,
            'compiled': self.compiled,
            'compile_error': self.compile_error[:500] if self.compile_error else "",
            'all_tests_passed': self.all_tests_passed,
            'test_results': self.test_results,
            'usage': self.usage,
            'query_time_sec': round(self.query_time_sec, 3),
            'code_length': len(self.code),
            'error': self.error,
        }

    @classmethod
    def from_dict(cls, d: Dict) -> 'SampleResult':
        sr = cls(d['slug'], d.get('sample_idx', 0), d.get('language', 'cpp'))
        sr.code = d.get('code', '')
        sr.compiled = d.get('compiled', False)
        sr.compile_error = d.get('compile_error', '')
        sr.test_results = d.get('test_results', [])
        sr.all_tests_passed = d.get('all_tests_passed', False)
        sr.usage = d.get('usage', {})
        sr.query_time_sec = d.get('query_time_sec', 0.0)
        sr.error = d.get('error', '')
        return sr


# ═══════════════════════════════════════════════════════════════════════════
# Main Evaluation Loop
# ═══════════════════════════════════════════════════════════════════════════

def run_evaluation(args: argparse.Namespace) -> Dict[str, Any]:
    """Run full benchmark evaluation."""
    RUNS_DIR.mkdir(parents=True, exist_ok=True)
    BENCHMARKS_DIR.mkdir(parents=True, exist_ok=True)

    timestamp = datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")
    run_id = f"run_{timestamp}_{args.model.replace('/', '_')}_{args.language}"
    run_file = RUNS_DIR / f"{run_id}.jsonl"

    compiler = find_compiler() if args.language == "cpp" else "python"
    if args.language == "cpp":
        if compiler:
            print(f"{C_GREEN}✓{C_RESET} C++ compiler: {C_BOLD}{compiler}{C_RESET}")
        else:
            print(f"{C_YELLOW}⚠{C_RESET} No C++ compiler found — code will be archived, run with --judge-only on a machine with g++.")
    else:
        print(f"{C_GREEN}✓{C_RESET} Python execution engine: {C_BOLD}{sys.executable}{C_RESET}")

    # Load problems
    problems = load_unique_problems()
    if args.difficulty:
        allowed = set(d.upper() for d in args.difficulty)
        problems = [p for p in problems if (p['difficulty'] or '').upper() in allowed]
    if args.slug:
        problems = [p for p in problems if p['slug'] in args.slug]

    evaluable = [p for p in problems if p['samples']]
    skipped_interactive = [p for p in problems if not p['samples']]

    # Resume support: load completed slugs from resume file
    completed_slugs: set = set()
    all_results: Dict[str, List[SampleResult]] = {}
    if args.resume:
        resume_path = Path(args.resume)
        if resume_path.exists():
            print(f"{C_CYAN}ℹ{C_RESET} Resuming from: {resume_path.name}")
            with open(resume_path, encoding='utf-8') as rf:
                for line in rf:
                    d = json.loads(line)
                    sr = SampleResult.from_dict(d)
                    all_results.setdefault(sr.slug, []).append(sr)
                    completed_slugs.add(sr.slug)
            print(f"  Loaded {len(completed_slugs)} completed problem(s).")

    print(f"\n{C_BOLD}{'═' * 70}{C_RESET}")
    print(f"{C_BOLD}  Xtreme-Bench Evaluation Harness{C_RESET}")
    print(f"{C_BOLD}{'═' * 70}{C_RESET}")
    print(f"  Model:        {C_CYAN}{args.model}{C_RESET}")
    print(f"  Language:     {C_CYAN}{args.language.upper()}{C_RESET}")
    print(f"  Samples/prob: {C_CYAN}{args.samples}{C_RESET}")
    print(f"  Temperature:  {C_CYAN}{args.temperature}{C_RESET}")
    print(f"  Delay:        {C_CYAN}{args.delay}s{C_RESET}")
    print(f"  Problems:     {C_CYAN}{len(evaluable)}{C_RESET} evaluable, "
          f"{C_DIM}{len(skipped_interactive)} interactive (skipped){C_RESET}")
    print(f"  Runtime:      {C_CYAN}{compiler or 'None'}{C_RESET}")
    print(f"  Run ID:       {C_DIM}{run_id}{C_RESET}")
    print(f"  Output:       {C_DIM}{run_file}{C_RESET}")
    print(f"{C_BOLD}{'═' * 70}{C_RESET}\n")

    client = None
    if not args.dry_run:
        try:
            from google import genai
            client = genai.Client()
            print(f"{C_GREEN}✓{C_RESET} Gemini API client initialized.\n")
        except Exception as e:
            print(f"{C_RED}✗{C_RESET} Failed to initialize Gemini client: {e}")
            sys.exit(1)
    else:
        print(f"{C_YELLOW}⚠{C_RESET} Dry run mode — no API calls will be made.\n")

    total_problems = len(evaluable)

    for prob_idx, problem in enumerate(evaluable):
        slug = problem['slug']
        if slug in completed_slugs:
            print(f"[{prob_idx + 1}/{total_problems}] {C_DIM}{slug} (already completed, skipped){C_RESET}")
            continue

        samples = problem['samples']
        time_limit = parse_time_limit_ms(problem['time_limit'])
        exec_timeout = max(time_limit * 3, EXEC_TIMEOUT_SEC)

        print(f"[{prob_idx + 1}/{total_problems}] {C_BOLD}{slug}{C_RESET} "
              f"({problem['difficulty'] or '?'}) "
              f"— {len(samples)} sample test(s), TL={problem['time_limit']}")

        problem_results: List[SampleResult] = []

        for sample_i in range(args.samples):
            sr = SampleResult(slug, sample_i, language=args.language)

            if args.dry_run:
                with open(DATASET_JSONL, encoding='utf-8') as f:
                    for line in f:
                        entry = json.loads(line)
                        if entry['metadata']['slug'] == slug:
                            sr.code = entry['output']
                            sr.response_text = sr.code
                            break
            else:
                try:
                    t0 = time.perf_counter()
                    response_text, usage = query_gemini(
                        client, args.model,
                        problem['statement'],
                        language=args.language,
                        temperature=args.temperature,
                    )
                    sr.query_time_sec = time.perf_counter() - t0
                    sr.response_text = response_text
                    sr.usage = usage
                    sr.code = extract_code(response_text, language=args.language)

                    time.sleep(args.delay)
                except Exception as e:
                    sr.error = f"API error: {e}"
                    print(f"  {C_RED}✗{C_RESET} Sample {sample_i}: API error — {e}")
                    problem_results.append(sr)
                    continue

            if not sr.code:
                sr.error = "No code extracted from response"
                print(f"  {C_RED}✗{C_RESET} Sample {sample_i}: No code in response")
                problem_results.append(sr)
                continue

            # Validate / Compile
            can_execute = (args.language == "python") or (args.language == "cpp" and compiler)
            if can_execute:
                with tempfile.TemporaryDirectory(prefix="xbench_") as tmpdir:
                    ok, target_path, cerr = validate_and_compile(
                        sr.code, args.language, compiler if args.language == "cpp" else None, tmpdir
                    )
                    sr.compiled = ok
                    sr.compile_error = cerr

                    if not ok:
                        print(f"  {C_RED}✗{C_RESET} Sample {sample_i}: "
                              f"{'Syntax' if args.language == 'python' else 'Compile'} error — {cerr[:80]}")
                        problem_results.append(sr)
                        with open(run_file, 'a', encoding='utf-8') as rf:
                            rf.write(json.dumps(sr.to_dict()) + '\n')
                        continue

                    # Run sample tests
                    all_passed = True
                    for test_i, (test_in, test_out) in enumerate(samples):
                        stdout, runtime, timed_out, run_err = run_solution(
                            target_path, test_in, exec_timeout, language=args.language
                        )
                        passed = False
                        if not timed_out and not run_err:
                            passed = judge_output(stdout, test_out)

                        sr.test_results.append({
                            'test_idx': test_i,
                            'passed': passed,
                            'runtime_sec': round(runtime, 4),
                            'timed_out': timed_out,
                            'error': run_err,
                        })

                        if not passed:
                            all_passed = False
                            status = "TLE" if timed_out else ("RE" if run_err else "WA")
                            detail = f"exp={test_out.strip()[:30]}, got={stdout.strip()[:30]}"
                            if status == "TLE":
                                detail = f">{exec_timeout}s"
                            elif status == "RE":
                                detail = run_err[:60]
                            print(f"    Test {test_i}: {C_RED}{status}{C_RESET} ({detail})")

                    sr.all_tests_passed = all_passed
                    if all_passed:
                        avg_rt = sum(t['runtime_sec'] for t in sr.test_results) / len(sr.test_results)
                        print(f"  {C_GREEN}✓{C_RESET} Sample {sample_i}: "
                              f"ALL PASSED ({len(samples)} tests, avg {avg_rt:.3f}s)")
                    else:
                        pass_count = sum(1 for t in sr.test_results if t['passed'])
                        print(f"  {C_RED}✗{C_RESET} Sample {sample_i}: "
                              f"{pass_count}/{len(samples)} tests passed")
            else:
                sr.compiled = False
                sr.compile_error = "no_compiler"
                print(f"  {C_DIM}?{C_RESET} Sample {sample_i}: "
                      f"Code extracted ({len(sr.code)} chars), saved for offline judging")

            problem_results.append(sr)

            # Persist to run file
            with open(run_file, 'a', encoding='utf-8') as rf:
                rf.write(json.dumps(sr.to_dict()) + '\n')

        all_results[slug] = problem_results
        print()

    # Compute metrics & update leaderboard
    metrics = compute_metrics(all_results, args.samples, evaluable, skipped_interactive)
    metrics['run_id'] = run_id
    metrics['model'] = args.model
    metrics['language'] = args.language
    metrics['temperature'] = args.temperature
    metrics['samples_per_problem'] = args.samples
    metrics['compiler'] = str(compiler)
    metrics['timestamp'] = datetime.now(timezone.utc).isoformat()
    metrics['dry_run'] = args.dry_run

    metrics_file = RUNS_DIR / f"{run_id}_metrics.json"
    with open(metrics_file, 'w', encoding='utf-8') as f:
        json.dump(metrics, f, indent=2)

    print_summary(metrics, compiler if args.language == "cpp" else sys.executable)
    update_leaderboard(metrics)
    return metrics


# ═══════════════════════════════════════════════════════════════════════════
# Judge-Only Mode (Offline Evaluation of Previous Run)
# ═══════════════════════════════════════════════════════════════════════════

def judge_existing_run(run_file_path: Path) -> Dict[str, Any]:
    """Grade an existing run file against sample tests without calling APIs."""
    if not run_file_path.exists():
        print(f"{C_RED}✗{C_RESET} Run file not found: {run_file_path}")
        sys.exit(1)

    print(f"\n{C_BOLD}Grading existing run:{C_RESET} {run_file_path.name}")
    problems_map = {p['slug']: p for p in load_unique_problems()}

    compiler = find_compiler()

    records: List[Dict] = []
    with open(run_file_path, encoding='utf-8') as f:
        for line in f:
            if line.strip():
                records.append(json.loads(line))

    all_results: Dict[str, List[SampleResult]] = {}
    total_records = len(records)

    for idx, d in enumerate(records):
        sr = SampleResult.from_dict(d)
        slug = sr.slug
        lang = sr.language
        prob = problems_map.get(slug)
        if not prob or not prob['samples']:
            all_results.setdefault(slug, []).append(sr)
            continue

        samples = prob['samples']
        time_limit = parse_time_limit_ms(prob['time_limit'])
        exec_timeout = max(time_limit * 3, EXEC_TIMEOUT_SEC)

        can_execute = (lang == "python") or (lang == "cpp" and compiler)
        if not can_execute:
            print(f"[{idx + 1}/{total_records}] {slug} — skipped (no {lang} runtime)")
            all_results.setdefault(slug, []).append(sr)
            continue

        with tempfile.TemporaryDirectory(prefix="xbench_judge_") as tmpdir:
            ok, target_path, cerr = validate_and_compile(
                sr.code, lang, compiler if lang == "cpp" else None, tmpdir
            )
            sr.compiled = ok
            sr.compile_error = cerr

            if not ok:
                sr.all_tests_passed = False
                print(f"[{idx + 1}/{total_records}] {slug} — {C_RED}Compile/Syntax Error{C_RESET}")
                all_results.setdefault(slug, []).append(sr)
                continue

            all_passed = True
            sr.test_results = []
            for test_i, (test_in, test_out) in enumerate(samples):
                stdout, runtime, timed_out, run_err = run_solution(
                    target_path, test_in, exec_timeout, language=lang
                )
                passed = False
                if not timed_out and not run_err:
                    passed = judge_output(stdout, test_out)
                sr.test_results.append({
                    'test_idx': test_i,
                    'passed': passed,
                    'runtime_sec': round(runtime, 4),
                    'timed_out': timed_out,
                    'error': run_err,
                })
                if not passed:
                    all_passed = False

            sr.all_tests_passed = all_passed
            icon = f"{C_GREEN}✓ PASS{C_RESET}" if all_passed else f"{C_RED}✗ FAIL{C_RESET}"
            print(f"[{idx + 1}/{total_records}] {slug} — {icon}")
            all_results.setdefault(slug, []).append(sr)

    # Re-write the run file with updated results
    with open(run_file_path, 'w', encoding='utf-8') as f:
        for slug_list in all_results.values():
            for sr in slug_list:
                f.write(json.dumps(sr.to_dict()) + '\n')

    evaluable = [p for p in problems_map.values() if p['samples']]
    skipped = [p for p in problems_map.values() if not p['samples']]
    metrics = compute_metrics(all_results, 1, evaluable, skipped)
    metrics['run_id'] = run_file_path.stem
    metrics['timestamp'] = datetime.now(timezone.utc).isoformat()
    metrics['model'] = run_file_path.stem.split('_gemini-')[1] if '_gemini-' in run_file_path.stem else "unknown"

    metrics_file = run_file_path.parent / f"{run_file_path.stem}_metrics.json"
    with open(metrics_file, 'w', encoding='utf-8') as f:
        json.dump(metrics, f, indent=2)

    print_summary(metrics, compiler)
    update_leaderboard(metrics)
    return metrics


# ═══════════════════════════════════════════════════════════════════════════
# Metrics & Leaderboard Formatting
# ═══════════════════════════════════════════════════════════════════════════

def compute_metrics(
    results: Dict[str, List[SampleResult]],
    k: int,
    evaluable: List[Dict],
    skipped: List[Dict],
) -> Dict[str, Any]:
    per_problem: List[Dict] = []
    by_difficulty: Dict[str, Dict[str, int]] = {}

    for problem in evaluable:
        slug = problem['slug']
        difficulty = problem['difficulty'] or 'UNKNOWN'

        if difficulty not in by_difficulty:
            by_difficulty[difficulty] = {'total': 0, 'passed': 0, 'compiled': 0}
        by_difficulty[difficulty]['total'] += 1

        if slug not in results:
            per_problem.append({
                'slug': slug, 'difficulty': difficulty,
                'n': 0, 'c': 0, 'pass_at_1': 0.0,
            })
            continue

        slug_results = results[slug]
        n = len(slug_results)
        c = sum(1 for sr in slug_results if sr.all_tests_passed)
        compiled_count = sum(1 for sr in slug_results if sr.compiled)

        p1 = pass_at_k(n, c, 1) if n >= 1 else 0.0
        pk = pass_at_k(n, c, min(k, n)) if n >= 1 else 0.0

        if c > 0:
            by_difficulty[difficulty]['passed'] += 1
        if compiled_count > 0:
            by_difficulty[difficulty]['compiled'] += 1

        per_problem.append({
            'slug': slug,
            'difficulty': difficulty,
            'n': n,
            'c': c,
            'compiled': compiled_count,
            'pass_at_1': round(p1, 4),
            f'pass_at_{k}': round(pk, 4),
        })

    total_problems = len(per_problem)
    overall_pass1 = (sum(p['pass_at_1'] for p in per_problem) / total_problems
                     if total_problems else 0.0)
    overall_passk_key = f'pass_at_{k}'
    overall_passk = (sum(p.get(overall_passk_key, 0.0) for p in per_problem) / total_problems
                     if total_problems else 0.0)

    return {
        'total_problems': total_problems,
        'skipped_interactive': len(skipped),
        'overall_pass_at_1': round(overall_pass1, 4),
        f'overall_pass_at_{k}': round(overall_passk, 4),
        'per_difficulty': {
            diff: {
                'total': info['total'],
                'passed': info['passed'],
                'compiled': info['compiled'],
                'pass_rate': round(info['passed'] / info['total'], 4) if info['total'] else 0.0,
            }
            for diff, info in sorted(by_difficulty.items())
        },
        'per_problem': sorted(per_problem, key=lambda p: p['slug']),
    }


def print_summary(metrics: Dict, compiler: Optional[str]) -> None:
    print(f"\n{C_BOLD}{'═' * 70}{C_RESET}")
    print(f"{C_BOLD}  EVALUATION RESULTS — {metrics.get('model', '?')} ({metrics.get('language', 'cpp').upper()}){C_RESET}")
    print(f"{C_BOLD}{'═' * 70}{C_RESET}")

    k = metrics.get('samples_per_problem', 1)
    print(f"\n  Overall Pass@1:  {C_BOLD}{C_GREEN}{metrics['overall_pass_at_1']:.1%}{C_RESET}")
    if k > 1:
        pk_key = f'overall_pass_at_{k}'
        print(f"  Overall Pass@{k}:  {C_BOLD}{C_GREEN}{metrics.get(pk_key, 0):.1%}{C_RESET}")

    print(f"\n  {C_BOLD}Per Difficulty:{C_RESET}")
    diff_order = ['TUTORIAL', 'EASY', 'MEDIUM', 'HARD', 'UNKNOWN']
    for diff in diff_order:
        if diff in metrics['per_difficulty']:
            info = metrics['per_difficulty'][diff]
            bar_len = int(info['pass_rate'] * 20)
            bar = '█' * bar_len + '░' * (20 - bar_len)
            color = C_GREEN if info['pass_rate'] >= 0.5 else (C_YELLOW if info['pass_rate'] > 0 else C_RED)
            print(f"    {diff:<10} {bar} {color}{info['pass_rate']:>6.1%}{C_RESET} "
                  f"({info['passed']}/{info['total']} solved, "
                  f"{info['compiled']}/{info['total']} compiled)")

    print(f"\n  Run saved to: {C_DIM}{metrics.get('run_id', 'unknown')}{C_RESET}")
    print(f"{C_BOLD}{'═' * 70}{C_RESET}\n")


def update_leaderboard(new_metrics: Dict) -> None:
    all_runs: List[Dict] = []
    if RUNS_DIR.exists():
        for f in sorted(RUNS_DIR.glob("*_metrics.json")):
            try:
                data = json.loads(f.read_text(encoding='utf-8'))
                all_runs.append(data)
            except Exception:
                pass

    if not any(r.get('run_id') == new_metrics.get('run_id') for r in all_runs):
        all_runs.append(new_metrics)

    all_runs.sort(key=lambda r: r.get('overall_pass_at_1', 0), reverse=True)

    lines: List[str] = []
    lines.append("# 🏆 Xtreme-Bench Leaderboard\n")
    lines.append("Competitive programming benchmark evaluation results across frontier LLMs.\n")
    lines.append(f"**Corpus:** [Xtreme-Bench on Hugging Face](https://huggingface.co/datasets/AaradhyaDT/Xtreme-Bench)  \n")
    lines.append(f"**Problems:** {new_metrics.get('total_problems', '?')} evaluable "
                 f"(+ {new_metrics.get('skipped_interactive', '?')} interactive, skipped)  \n")
    lines.append(f"**Last Updated:** {datetime.now().strftime('%Y-%m-%d %H:%M UTC')}\n")
    lines.append("---\n")

    lines.append("## Overall Rankings\n")
    lines.append("| Rank | Model | Lang | Pass@1 | Compiled | Temperature | Samples | Date |")
    lines.append("| :---: | :--- | :---: | :---: | :---: | :---: | :---: | :--- |")

    for rank, run in enumerate(all_runs, 1):
        model = run.get('model', '?')
        lang = run.get('language', 'cpp').upper()
        p1 = run.get('overall_pass_at_1', 0)
        total_compiled = sum(d.get('compiled', 0) for d in run.get('per_difficulty', {}).values())
        total_probs = sum(d.get('total', 0) for d in run.get('per_difficulty', {}).values())
        compiled_pct = f"{total_compiled}/{total_probs}" if total_probs else "—"
        temp = run.get('temperature', '?')
        samples = run.get('samples_per_problem', 1)
        ts = run.get('timestamp', '?')[:10]
        dry = " *(dry)*" if run.get('dry_run') else ""

        medal = "🥇" if rank == 1 else ("🥈" if rank == 2 else ("🥉" if rank == 3 else f"{rank}"))
        lines.append(
            f"| {medal} | **{model}**{dry} | `{lang}` | "
            f"**{p1:.1%}** | {compiled_pct} | {temp} | {samples} | {ts} |"
        )

    lines.append("")
    lines.append("## Per-Difficulty Breakdown (Latest Run)\n")
    lines.append(f"**Model:** `{new_metrics.get('model', '?')}` (`{new_metrics.get('language', 'cpp').upper()}`)  \n")
    lines.append(f"**Run ID:** `{new_metrics.get('run_id', '?')}`\n")
    lines.append("| Difficulty | Solved | Compiled | Pass Rate |")
    lines.append("| :--- | :---: | :---: | :---: |")

    diff_order = ['TUTORIAL', 'EASY', 'MEDIUM', 'HARD', 'UNKNOWN']
    for diff in diff_order:
        if diff in new_metrics.get('per_difficulty', {}):
            info = new_metrics['per_difficulty'][diff]
            lines.append(
                f"| {diff} | {info['passed']}/{info['total']} | "
                f"{info['compiled']}/{info['total']} | "
                f"**{info['pass_rate']:.1%}** |"
            )

    lines.append("")
    lines.append("## Per-Problem Results (Latest Run)\n")
    lines.append("| Problem Slug | Difficulty | Compiled | Correct | Pass@1 |")
    lines.append("| :--- | :---: | :---: | :---: | :---: |")

    for prob in new_metrics.get('per_problem', []):
        slug = prob['slug']
        diff = prob.get('difficulty', '?')
        n = prob.get('n', 0)
        c = prob.get('c', 0)
        compiled = prob.get('compiled', 0)
        p1 = prob.get('pass_at_1', 0)
        icon = "✅" if p1 >= 0.999 else ("🟡" if p1 > 0 else "❌")
        lines.append(
            f"| [{slug}](../platforms/csacademy/tasks/{slug}/statement.md) | "
            f"{diff} | {compiled}/{n} | {c}/{n} | {icon} {p1:.1%} |"
        )

    lines.append("")
    lines.append("---\n")
    lines.append("*Generated by [`scripts/eval_bench.py`](../scripts/eval_bench.py)*\n")

    LEADERBOARD_FILE.parent.mkdir(parents=True, exist_ok=True)
    LEADERBOARD_FILE.write_text('\n'.join(lines), encoding='utf-8')
    print(f"{C_GREEN}✓{C_RESET} Leaderboard updated: {LEADERBOARD_FILE.relative_to(REPO_ROOT)}")


# ═══════════════════════════════════════════════════════════════════════════
# CLI Entrypoint
# ═══════════════════════════════════════════════════════════════════════════

def main():
    parser = argparse.ArgumentParser(
        description="Xtreme-Bench: Competitive Programming LLM Evaluation Harness",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--model", default="gemini-3.8-flash",
        help="Model identifier (default: gemini-3.8-flash). "
             "Use gemini-3.1-pro-preview for top-tier reasoning.",
    )
    parser.add_argument(
        "--language", choices=["cpp", "python"], default="cpp",
        help="Target language for generated solutions (cpp or python, default: cpp).",
    )
    parser.add_argument(
        "--samples", type=int, default=1,
        help="Number of solution samples per problem for Pass@k (default: 1).",
    )
    parser.add_argument(
        "--temperature", type=float, default=1.0,
        help="Sampling temperature (default: 1.0). Gemini 3.x models are tuned for 1.0.",
    )
    parser.add_argument(
        "--difficulty", nargs="+",
        help="Filter problems by difficulty (TUTORIAL, EASY, MEDIUM, HARD).",
    )
    parser.add_argument(
        "--slug", nargs="+",
        help="Evaluate only specific problem slug(s).",
    )
    parser.add_argument(
        "--delay", type=float, default=API_DELAY_SEC,
        help=f"Seconds to pause between API calls (default: {API_DELAY_SEC}). "
             "Paid-tier users can lower to 1-2.",
    )
    parser.add_argument(
        "--dry-run", action="store_true",
        help="Test the harness without API calls (uses human solutions).",
    )
    parser.add_argument(
        "--judge-only", type=str,
        help="Grade an existing run JSONL file offline without querying APIs.",
    )
    parser.add_argument(
        "--resume", type=str,
        help="Resume an interrupted run JSONL file.",
    )

    args = parser.parse_args()

    if args.judge_only:
        judge_existing_run(Path(args.judge_only))
    else:
        run_evaluation(args)


if __name__ == "__main__":
    main()
