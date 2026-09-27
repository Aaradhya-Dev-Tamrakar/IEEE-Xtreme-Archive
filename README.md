# IEEE-Xtreme-Archive 🏆

Autonomous Competitive Programming corpus, structured problem statements with LaTeX/KaTeX mathematical formulas, and verified 100-point optimal solutions archive for **IEEEXtreme**, **PreXtreme**, and **CS Academy**.

---

## 📊 Live Archive Progress Dashboard

| Metric | Count / Status | Notes |
| :--- | :--- | :--- |
| **Total Discovered Tasks** | `669` | Cataloged in [`ledger/tasks_index.json`](ledger/tasks_index.json) |
| **Fully Archived Statements** | `662` | 98.9% (remaining 7 are unreleased origin tasks) |
| **Completed Statistics** | `669` | 100.0% coverage across full archive |
| **Archived Optimal Solutions** | `532` | Un-truncated source files + test matrices |
| **Active Platform** | `CS Academy` | Primary judge for PreXtreme & training contests |
| **Harvester Engine** | `CDP Asynchronous Engine` | Headless WebSocket CDP attached to Chrome |
| **Google Drive Archive** | [`IEEE-Xtreme-Archive`](https://drive.google.com/drive/folders/1Z2IAQ7Sf1pZWTn5EniiSBpuH7gLeaWLu) | Briefings subfolder: [`1DrXUosZl3...`](https://drive.google.com/drive/folders/1DrXUosZl3_Ihh8Ud2ZTW83aL6g7NA-iu) |
| **NotebookLM Corpus** | [IEEE-Xtreme Algorithmic Corpus](https://notebooklm.google.com/notebook/071b19a5-960f-429c-91e4-384669bea974) | Grounded with 12 sources via `super-nlm` (`071b19a5...`) |

### Harvested Tasks Sample (30 Completed)

| Task Slug | Task Title | Difficulty | Solved Ratio | Archived Solutions | Problem Statement |
| :--- | :--- | :---: | :---: | :---: | :---: |
| `addition` | Addition | TUTORIAL | 94% (13712 / 14479) | 20 | [statement.md](platforms/csacademy/tasks/addition/statement.md) |
| `gcd` | Greatest Common Divisor | TUTORIAL | 79% (8124 / 10228) | 20 | [statement.md](platforms/csacademy/tasks/gcd/statement.md) |
| `matrix_exploration` | Matrix Exploration | EASY | 68% (1719 / 2504) | 17 | [statement.md](platforms/csacademy/tasks/matrix_exploration/statement.md) |
| `word_ordering` | Word Ordering (Beta Round #1) | EASY | 71% (1588 / 2222) | 20 | [statement.md](platforms/csacademy/tasks/word_ordering/statement.md) |
| `sorting_partition` | Sorting Partition (Beta Round #1) | EASY | 71% (1198 / 1686) | 20 | [statement.md](platforms/csacademy/tasks/sorting_partition/statement.md) |
| `swap_permutation` | Swap Permutation (Beta Round #1) | MEDIUM | 62% (581 / 923) | 20 | [statement.md](platforms/csacademy/tasks/swap_permutation/statement.md) |
| `two_progressions` | Two Progressions (Beta Round #1) | HARD | 58% (167 / 286) | 20 | [statement.md](platforms/csacademy/tasks/two_progressions/statement.md) |
| `online_xormax` | Online XOR Max | HARD | 37% (74 / 197) | 17 | [statement.md](platforms/csacademy/tasks/online_xormax/statement.md) |
| *... and 22 more* | *(See `ledger/archive_ledger.json` for full list)* | — | — | — | — |

---

## 📂 Repository Topology & Storage Schema

```text
IEEE-Xtreme-Archive/
├── ARCHIVAL_PLAN_AND_HANDOVER.md       # Master architectural blueprint & execution specs
├── README.md                           # Live status dashboard & usage instructions
├── audit/                              # Quality audits & formal verification
│   └── corpus_audit.md                 # Adversarial audit report (99.85% health score)
├── briefings/                          # Algorithmic archetypes & NotebookLM study guides
│   ├── catalog.md                      # Master catalog of 669 tasks across 10 archetypes
│   └── 01_dynamic_programming.md ...   # Topic guides (DP, Graphs, Trees, Range Queries, etc.)
├── cli/                                # Offline practice and auto-testing runner
│   ├── solve.py                        # Interactive CLI (list, pick, test against sample I/O)
│   └── README.md                       # CLI documentation and guide
├── datasets/                           # Machine learning instruction-tuning datasets
│   └── cp_instruction_dataset.jsonl    # Dual Alpaca/ShareGPT dataset (474 optimal pairs)
├── harvesters/                         # Autonomous extraction & CDP scraping engines
│   ├── cdp_engine.py                   # Async Chrome DevTools Protocol (CDP) client
│   └── csacademy_harvester.py          # CS Academy pipeline runner & solution archiver
├── ledger/                             # Resumable checkpoint ledgers & task discovery indexes
│   ├── tasks_index.json                # Master index of all 669 discovered tasks
│   ├── jobs_queue.json                 # Pending & archived solution job queue
│   ├── archive_ledger.json             # Execution checkpoint ledger
│   └── corpus.db                       # Sub-millisecond SQLite database with FTS5 search
├── scripts/                            # Dataset and database generation pipelines
│   └── generate_datasets.py            # High-speed ETL script (0.438s build time)
├── skills/
│   └── cp-archive-harvester/
│       └── SKILL.md                    # Dedicated Antigravity skill handbook
└── platforms/
    └── csacademy/
        ├── evaluation_environment.json # Ubuntu 25.04 & compiler runtime specifications
        └── tasks/
            └── <task_slug>/            # 662 archived tasks (addition, gcd, etc.)
                ├── problem.json        # Limits, score type, metadata
                ├── statement.md        # Full Markdown statement with LaTeX math & I/O tables
                ├── statistics.json     # Solvers count, top CPU & memory solutions
                └── submissions/
                    ├── index.json      # Registry of all optimal solutions for this task
                    └── <job_id>/       # 532 optimal solutions
                        ├── metadata.json # Author, verdict, runtime, memory, language
                        ├── solution.<ext># Pristine un-truncated source code (cpp, py, java)
                        └── results.json  # Granular per-test-case verification matrix
```

---

## ⚡ Grounded Judge Environment (CS Academy / PreXtreme)

* **Host Operating System:** x64 Ubuntu 25.04
* **C++ Compiler:** `g++ 15.2.0` (`-std=c++23 -static -O2 -pthread -Wall -Wno-unused-result -DCS_ACADEMY -DONLINE_JUDGE`)
  * *Available Libraries:* Boost 1.90, Eigen 3.4.0, AC Library (`<atcoder/all>`), GMP 6.3.0, MPFR 4.2.2, zlib, bzip2, liblzma, zstd.
* **Python Environments:**
  * Python 3.13.3 (with `numpy` and `scipy`)
  * PyPy3: Python 3.11.11, PyPy 7.9.13
* **Java:** OpenJDK 21 (`-XX:+UseSerialGC -Xmx4g -Xss256m -DONLINE_JUDGE -DCS_ACADEMY Main`)
* **Execution Constraints:** Multithreading enabled; total CPU time is aggregate across all threads.

---

## 🚀 Harvester CLI Usage

The autonomous harvester is driven by [`harvesters/csacademy_harvester.py`](harvesters/csacademy_harvester.py) via CDP:

### 1. Launch Chrome with Remote Debugging
```powershell
Start-Process "C:\Program Files\Google\Chrome\Application\chrome.exe" -ArgumentList @(
    "--remote-debugging-port=9222",
    '--profile-directory=Profile 6',
    "--restore-last-session"
)
```

### 2. Run Commands

* **Discover & Catalog All Tasks:**
  ```powershell
  python harvesters/csacademy_harvester.py --discover
  ```

* **Harvest a Single Task (with all optimal solutions):**
  ```powershell
  python harvesters/csacademy_harvester.py --slug addition
  ```

* **Harvest Next Batch of Tasks:**
  ```powershell
  python harvesters/csacademy_harvester.py --max-tasks 20
  ```

* **Run Full Autonomous Run (All Tasks):**
  ```powershell
  python harvesters/csacademy_harvester.py
  ```

All runs are fully checkpointed in `ledger/archive_ledger.json` and can be safely interrupted and resumed at any time.

### 3. Repository Synchronization (`sync.ps1`)

All git operations are protected by the repository's dedicated `sync.ps1` synchronization engine:
```powershell
# Routine auto-sync with secret scanning & integrity check:
.\sync.ps1

# Semantic feature commit:
.\sync.ps1 -m "feat(scope): detailed summary"

# Safe pull only:
.\sync.ps1 -PullOnly
```

---

## 🧠 Dedicated Antigravity Skill (`cp-archive-harvester`)

This repository is equipped with a dedicated autonomous skill specification:
* **Repository Mirror:** [`skills/cp-archive-harvester/SKILL.md`](skills/cp-archive-harvester/SKILL.md)
* **Global Antigravity Skill:** [`C:\Users\Aaradhya\.gemini\config\skills\cp-archive-harvester\SKILL.md`](file:///C:/Users/Aaradhya/.gemini/config/skills/cp-archive-harvester/SKILL.md)

Whenever continuing the archival or harvesting new CP platforms, the agent loads this skill to enforce:
1. Automated Chrome CDP lifecycle management and safe PowerShell argument escaping.
2. Lossless KaTeX formula conversion into Markdown LaTeX math (`$...$` / `$$...$$`).
3. Direct extraction of un-truncated source code from editor buffers.
4. Granular per-test-case verification matrix indexing.

---

## 🛡️ License & Epistemic Provenance
Maintained by [Aaradhya Dev Tamrakar](https://github.com/Aaradhya-Dev-Tamrakar) as part of the ecosystem intelligence mesh.
