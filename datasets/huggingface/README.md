---
annotations_creators:
- machine-generated
- expert-generated
language_creators:
- crowdsourced
- expert-generated
language:
- en
- cpp
license: mit
multilinguality:
- monolingual
size_categories:
- n<1K
source_datasets:
- original
task_categories:
- text-generation
- question-answering
task_ids:
- code-generation
tags:
- competitive-programming
- reasoning
- reinforcement-learning
- rlvr
- ieee-xtreme
- csacademy
- code-reasoning
- olympiad-informatics
pretty_name: "Xtreme-Bench: Competitive Programming Reasoning Corpus"
dataset_info:
  features:
  - name: instruction
    dtype: string
  - name: input
    dtype: string
  - name: output
    dtype: string
  - name: conversations
    list:
    - name: from
      dtype: string
    - name: value
      dtype: string
  - name: metadata
    struct:
    - name: slug
      dtype: string
    - name: difficulty
      dtype: string
    - name: time_limit
      dtype: string
    - name: memory_limit
      dtype: string
    - name: cpu_time
      dtype: string
    - name: memory
      dtype: string
    - name: language
      dtype: string
    - name: job_id
      dtype: string
    - name: user
      dtype: string
    - name: solver
      dtype: string
    - name: verdict
      dtype: string
  splits:
  - name: train
    num_bytes: 4478200
    num_examples: 474
  download_size: 4478200
  dataset_size: 4478200
configs:
- config_name: default
  data_files:
  - split: train
    path: data/train.jsonl
---

# 🚀 Xtreme-Bench: Competitive Programming Reasoning & Optimal Code Corpus

> **An out-of-distribution, contamination-resilient dataset of 474 paired algorithmic problem statements with verified 100-point C++ solutions, execution metrics, and full solver attribution.**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![IEEE-Xtreme](https://img.shields.io/badge/IEEE--Xtreme-PreXtreme-blue.svg)](https://ieeextreme.org/)
[![Corpus Health: 99.85%](https://img.shields.io/badge/Audit%20Health-99.85%25-brightgreen.svg)](https://github.com/Aaradhya-Dev-Tamrakar/IEEE-Xtreme-Archive)

---

## 📌 Dataset Summary

**Xtreme-Bench** is a specialized benchmark and instruction-tuning dataset harvested from the archived problem sets of **CS Academy** and **IEEE PreXtreme**. The problems are authored by International Olympiad in Informatics (IOI) medalists, Romanian National Olympiad trainers, and IEEE-Xtreme grandmasters.

### Why Xtreme-Bench?
1. **Contamination Resilient:** Because CS Academy operated via dynamic WebSocket and single-page React architectures, this problem set was largely omitted from standard web-scrape training dumps (e.g. Common Crawl, The Stack).
2. **Dual Schema Support:** Every example is pre-formatted for both **Alpaca** (`instruction`, `input`, `output`) and **ShareGPT** (`conversations`) loaders, ready for immediate fine-tuning with Axolotl, LLaMA-Factory, or Unsloth.
3. **Execution Profiles & Hardware Limits:** Each record includes precise CPU time (ms), peak memory usage (KB), time limit, memory limit, and difficulty.
4. **Verified Authorship & Provenance:** Unlike noisy code scrapes, every solution is attributed to the grandmaster solver who submitted the 100-point solution.

---

## 📊 Dataset Structure

### Supported Tasks
- **Supervised Fine-Tuning (SFT):** Training models to solve complex graph theory, dynamic programming, and computational geometry problems.
- **Reinforcement Learning from Verifiable Rewards (RLVR):** Using problem statements and sample input/output tables to evaluate reasoning models (similar to DeepSeek-R1 or OpenAI o1/o3 evaluations).
- **Complexity-Conditioned Code Generation:** Prompting models to synthesize algorithms that respect strict runtime budgets ($O(N \log N)$ vs $O(N^2)$).

### Feature Schema
| Feature | Type | Description |
| :--- | :--- | :--- |
| `instruction` | `string` | System prompt: *"You are a competitive programming grandmaster. Solve the following algorithmic problem with optimal time and memory complexity."* |
| `input` | `string` | Complete problem statement in Markdown with verbatim KaTeX LaTeX formulas, input/output specifications, constraints, and sample I/O tables. |
| `output` | `string` | The verified 100-point C++ solution code. |
| `conversations` | `list` | ShareGPT formatted multi-turn conversation structure (`human` $	o$ `gpt`). |
| `metadata.slug` | `string` | Unique task slug identifier. |
| `metadata.difficulty` | `string` | Problem difficulty (`EASY`, `MEDIUM`, `HARD`, `TUTORIAL`). |
| `metadata.time_limit` | `string` | Execution time limit (e.g., `1000 ms`). |
| `metadata.memory_limit` | `string` | Memory limit (e.g., `128 MB`). |
| `metadata.cpu_time` | `string` | CPU time achieved by the optimal solution. |
| `metadata.memory` | `string` | Peak memory consumed by the optimal solution. |
| `metadata.language` | `string` | Solution language (`C++`). |
| `metadata.user` / `solver` | `string` | Username or handle of the solver who authored the verified solution. |
| `metadata.verdict` | `string` | Submission verdict (`100 points`). |

---

## 🗂️ Taxonomic Distribution across 10 Algorithmic Archetypes

The problems in this benchmark span 10 foundational competitive programming paradigms:

| Archetype | Key Paradigms & Invariants |
| :--- | :--- |
| **01. Dynamic Programming** | Tree DP, Bitmask DP, Digit DP, Interval DP, Matrix Exponentiation |
| **02. Graph Theory & Network Flows** | Shortest Paths, 2-SAT, Max Flow, Min Cut, Bipartite Matching, SCC |
| **03. Trees & LCA** | Binary Lifting, Heavy-Light Decomposition, Centroid Decomposition |
| **04. Range Queries & Structures** | Segment Tree, Fenwick Tree, Mo's Algorithm, Sparse Table, Treap, DSU |
| **05. Combinatorics & Number Theory** | Inclusion-Exclusion, Modulo Arithmetic, NTT/FFT, Prime Sieve |
| **06. Greedy & Two Pointers** | Interval Scheduling, Sliding Window, Monotonic Binary Search |
| **07. Computational Geometry** | Vectors, Cross Product, Convex Hull, Rotating Calipers |
| **08. String Algorithms** | KMP, Z-algorithm, Suffix Automaton, Aho-Corasick, Manacher |
| **09. Game Theory & Nim Games** | Sprague-Grundy, Nim-sum, Impartial Games, Minimax on DAGs |
| **10. Constructive & Interactive** | Interactive Query Protocols, Parity Invariants, Permutations |

---

## 💻 Quick Start & Usage

### Loading with Hugging Face Datasets
```python
from datasets import load_dataset

# Load directly from Hugging Face Hub
dataset = load_dataset("AaradhyaDT/Xtreme-Bench", split="train")

print(f"Total training examples: {len(dataset)}")
sample = dataset[0]
print(f"Task: {sample['metadata']['slug']}")
print(f"Solver: {sample['metadata']['solver']}")
print(f"Difficulty: {sample['metadata']['difficulty']}")
```

### Loading with Unsloth / Axolotl
Because the dataset provides native Alpaca keys (`instruction`, `input`, `output`) and ShareGPT format, it can be passed directly into fine-tuning configs:

```yaml
# Axolotl dataset config example
datasets:
  - path: AaradhyaDT/Xtreme-Bench
    type: alpaca
```

---

## 📜 Citation & Attribution

If you use this dataset or benchmark in your research, please cite:

```bibtex
@misc{tamrakar2026xtremebench,
  author = {Aaradhya Dev Tamrakar},
  title = {Xtreme-Bench: A Contamination-Resilient Competitive Programming Reasoning Corpus},
  year = {2026},
  publisher = {Hugging Face},
  howpublished = {\url{https://huggingface.co/datasets/AaradhyaDT/Xtreme-Bench}},
  note = {Archived from CS Academy and IEEE PreXtreme challenge environments}
}
```

---

## 🛡️ License & Ethics
- **Dataset License:** MIT License.
- **Attribution Notice:** All individual solutions remain the intellectual creation of their respective solvers, credited under `metadata.solver`. Statements and problem formulations originated from CS Academy and IEEE-Xtreme.
