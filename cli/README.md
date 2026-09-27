# ⚡ IEEE-Xtreme-Archive Offline Practice CLI (`cli/solve.py`)

A lightweight, zero-dependency command-line utility for competitive programmers to discover, inspect, solve, and test algorithms offline against the harvested IEEE-Xtreme and CS Academy problem archives.

---

## 🌟 Key Capabilities

1. **Offline Task Discovery (`list`)**:
   - Filter over 660+ archived tasks by difficulty (`EASY`, `MEDIUM`, `HARD`, `TUTORIAL`) and keyword tags (e.g. `graph`, `tree`, `dp`, `math`, `Beta Round`).
   - Clean, colorized tabular summary with solved ratios, limits, and contest metadata.

2. **Problem Inspector & Randomizer (`pick`)**:
   - Randomly pick a task matching your target difficulty for practice sessions.
   - Inspect time limits, memory limits, clickable paths to local `statement.md`, web links, and sample preview.
   - Check the number of available sample test cases and archived 100-point benchmark solutions.

3. **Automated Sample Testing (`test`)**:
   - Parses Markdown sample tables and multiline inputs/outputs directly from `statement.md`.
   - Compiles C++ (`g++ -O2 -std=c++20` / `clang++` / `cl`) or runs Python (`.py`) solutions out-of-the-box.
   - Feeds test inputs into standard input, enforces timeouts, normalizes whitespace/newlines, and measures execution runtime in milliseconds.
   - Generates unified diffs on failure for debugging.

4. **Archived Optimal Benchmark Comparison**:
   - Compares your local execution time against the archive's top 100-point submissions (`submissions/index.json`).
   - Displays fastest submission, median submission time, and author stats.

---

## 🚀 Quick Start

No `pip install` required! Built entirely with the Python Standard Library.

```bash
# 1. List available EASY problems tagged with 'matrix'
python cli/solve.py list --difficulty EASY --tag matrix

# 2. Pick a random MEDIUM task to solve
python cli/solve.py pick --difficulty MEDIUM --random

# 3. Read the statement and write your solution (e.g. addition.py)
# 4. Test your solution against the problem's sample test suite
python cli/solve.py test cli/test_solutions/addition.py --slug addition
```

---

## 📖 Command Reference

### 1. `list` — Browse Archived Problems

```bash
# List all easy tasks (default shows first 40)
python cli/solve.py list --difficulty EASY

# Search tasks by keyword (slug, title, or contest)
python cli/solve.py list --tag tree

# Combine difficulty and tag with custom limit
python cli/solve.py list --difficulty HARD --tag "Round #10" --limit 15

# Display all matching tasks without truncation
python cli/solve.py list --difficulty TUTORIAL --all
```

**Options**:
- `--difficulty`, `-d`: Filter by `EASY`, `MEDIUM`, `HARD`, or `TUTORIAL`.
- `--tag`, `-t`: Filter by keyword substring (case-insensitive) across title, slug, or contest.
- `--limit`, `-l`: Maximum tasks to display (default: `40`).
- `--all`, `-a`: Show all matching tasks.
- `--no-color`: Disable ANSI color escape codes.

---

### 2. `pick` — Select and Inspect a Problem

```bash
# Pick a specific task by slug
python cli/solve.py pick --slug matrix_exploration

# Pick a random EASY problem
python cli/solve.py pick --difficulty EASY --random

# Pick a random problem matching a tag
python cli/solve.py pick --tag graph --random
```

**Card Preview Output**:
```text
╔══════════════════════════════════════════════════════════════════════════════╗
║  📌 TASK: Matrix Exploration                                                 ║
╠══════════════════════════════════════════════════════════════════════════════╣
  Slug:             matrix_exploration
  Difficulty:       EASY
  Contest:          Standard Archive
  Time Limit:       1000 ms
  Memory Limit:     128 MB
  Solved Ratio:     68% (1719 solved / 2504 tried)
  Statement File:   platforms\csacademy\tasks\matrix_exploration\statement.md
  File URI:         file:///F:/Aaradhya-Dev-Tamrakar/IEEE-Xtreme-Archive/platforms/csacademy/tasks/matrix_exploration/statement.md
  Web URL:          https://csacademy.com/contest/archive/task/matrix_exploration/

  Samples Available:    1 sample test case(s)
  Archived 100pt Subs:  17 solutions (Fastest: 21 ms by Mohammad Rehan)
╚══════════════════════════════════════════════════════════════════════════════╝
```

---

### 3. `test` — Validate Solutions Offline

```bash
# Test a Python solution with explicit slug
python cli/solve.py test my_solution.py --slug word_ordering

# Test with automatic slug inference (when filename matches slug)
python cli/solve.py test addition.py

# Test a C++ solution
python cli/solve.py test solution.cpp --slug addition
```

#### Successful Test Run
```text
🧪 Testing: addition.py  ⟶  Task: addition
Time Limit: 500 ms  |  Memory Limit: 128 MB  |  Samples: 2
Interpreter: python.exe (Python 3.14.7)

   PASS  Sample #1     31.4 ms
   PASS  Sample #2     29.4 ms

──────────────────────────────────────────────────────────────────────────────
⚡ ARCHIVED BENCHMARK COMPARISON (addition)
──────────────────────────────────────────────────────────────────────────────
  Archived 100-pt Best:    0 ms (Alexander Golovanov, C++)
  Archived 100-pt Median:  3 ms (across 20 solutions)
  Your Local Sample Avg:   30.4 ms (Python 3.14.7)
  Local Verdict:            ALL SAMPLES PASSED [2/2]  ✅
──────────────────────────────────────────────────────────────────────────────
```

#### Test Run with Failures and Diffs
When an answer fails, `solve.py` displays the input, expected vs actual outputs, and a colorized unified diff:

```text
   FAIL  Sample #1     28.6 ms (Wrong Answer)

    Input:
      10 20

    Expected Output:
      30

    Actual Output:
      200

    Diff:
      --- Expected
      +++ Actual
      @@ -1 +1 @@
      -30
      +200
```

---

## 🛠️ Languages Supported

- **Python (`.py`)**: Runs directly using `sys.executable`.
- **C++ (`.cpp`, `.cc`, `.cxx`)**:
  - Automatically searches PATH for `g++`, `clang++`, or MSVC `cl.exe`.
  - Compiles with optimization flags: `g++ -O2 -std=c++20 <source> -o <temp_binary>` (with automatic fallback to `-std=c++17`).
  - Cleans up temporary compiled binaries automatically after testing.

---

## 📁 Pre-Included Test Solutions

Verification test solutions are included in [`cli/test_solutions/`](file:///F:/Aaradhya-Dev-Tamrakar/IEEE-Xtreme-Archive/cli/test_solutions):
- `cli/test_solutions/addition.py` — Optimal Python solution for `addition`
- `cli/test_solutions/matrix_exploration.py` — Multi-source BFS solution for `matrix_exploration`
- `cli/test_solutions/word_ordering.py` — Custom lexicographical sort solution for `word_ordering`
- `cli/test_solutions/failing_addition.py` — Negative test case verifying diff and failure diagnostics
