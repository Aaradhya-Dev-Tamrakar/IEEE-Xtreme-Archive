# IEEE-Xtreme-Archive 🏆

Automated Competitive Programming corpus, structured problem statements with LaTeX/KaTeX mathematical formulas, and verified 100-point optimal solutions archive for **IEEEXtreme**, **PreXtreme**, and **CS Academy**.

---

## 📂 Repository Topology

```text
IEEE-Xtreme-Archive/
├── harvesters/                      # Reusable autonomous extraction & CDP scraping engines
│   ├── cdp_engine.py                # Headless Chrome DevTools Protocol client
│   └── csacademy_harvester.py       # CS Academy platform crawler & solution archiver
├── platforms/
│   └── csacademy/
│       ├── evaluation_environment.json  # Official Ubuntu 25.04 & compiler runtime specifications
│       ├── tasks/                       # Full problem statements, LaTeX math, limits, and sample I/O
│       └── solutions/                   # 100-point optimal solutions (lowest CPU time & memory)
├── datasets/                        # Compiled datasets for fine-tuning & local code LLMs
└── ledger/                          # Checkpoint ledgers & task discovery indexes
```

---

## ⚡ Grounded Judge Environment (CS Academy / PreXtreme)

* **Operating System:** x64 Ubuntu 25.04
* **C++ Compiler:** `g++ 15.2.0` (`-std=c++23 -static -O2 -pthread -Wall -Wno-unused-result -DCS_ACADEMY -DONLINE_JUDGE`)
  * *Libraries:* Boost 1.90, Eigen 3.4.0, AC Library (`<atcoder/all>`), GMP 6.3.0, MPFR 4.2.2
* **Python:** Python 3.13.3 (with `numpy` and `scipy`) & PyPy3 (Python 3.11.11 / PyPy 7.9.13)
* **Java:** OpenJDK 21 (`-XX:+UseSerialGC -Xmx4g -Xss256m`)

---

## 🚀 Execution & Usage

1. **Launch Chrome with CDP Debugging:**
   ```powershell
   chrome.exe --remote-debugging-port=9222 --profile-directory="Profile 6"
   ```
2. **Run Autonomous Harvester:**
   ```powershell
   python harvesters/csacademy_harvester.py --all-tasks
   ```

---

## 🛡️ License & Epistemic Provenance
Maintained by [Aaradhya Dev Tamrakar](https://github.com/Aaradhya-Dev-Tamrakar) as part of the ecosystem intelligence mesh.
