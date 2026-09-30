"""
Prepare Hugging Face dataset directory with standard Hub structure,
data/train.jsonl, and comprehensive YAML-frontmatter README.md Dataset Card.
"""

import json
import shutil
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parent.parent
SOURCE_JSONL = ROOT_DIR / "datasets" / "cp_instruction_dataset.jsonl"
HF_DIR = ROOT_DIR / "datasets" / "huggingface"
DATA_DIR = HF_DIR / "data"

DATASET_CARD = """---
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
| `conversations` | `list` | ShareGPT formatted multi-turn conversation structure (`human` $\to$ `gpt`). |
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
  howpublished = {\\url{https://huggingface.co/datasets/AaradhyaDT/Xtreme-Bench}},
  note = {Archived from CS Academy and IEEE PreXtreme challenge environments}
}
```

---

## 🛡️ License & Ethics
- **Dataset License:** MIT License.
- **Attribution Notice:** All individual solutions remain the intellectual creation of their respective solvers, credited under `metadata.solver`. Statements and problem formulations originated from CS Academy and IEEE-Xtreme.
"""


def main():
    print(f"Setting up Hugging Face dataset in {HF_DIR}...")
    DATA_DIR.mkdir(parents=True, exist_ok=True)

    # 1. Copy JSONL into data/train.jsonl
    target_jsonl = DATA_DIR / "train.jsonl"
    shutil.copy2(SOURCE_JSONL, target_jsonl)
    print(f"Copied dataset to {target_jsonl} ({target_jsonl.stat().st_size / 1024 / 1024:.2f} MB)")

    # 2. Write README.md dataset card
    readme_path = HF_DIR / "README.md"
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(DATASET_CARD)
    print(f"Generated Dataset Card at {readme_path}")

    # 3. Write upload script
    uploader_path = ROOT_DIR / "scripts" / "upload_to_hf.py"
    uploader_code = '''#!/usr/bin/env python3
"""
Upload Xtreme-Bench dataset to Hugging Face Hub.
Usage:
    python scripts/upload_to_hf.py --repo-id <username>/Xtreme-Bench [--token <hf_token>]
"""

import argparse
import os
import sys
from pathlib import Path
from huggingface_hub import HfApi, create_repo

ROOT = Path(__file__).resolve().parent.parent
HF_DIR = ROOT / "datasets" / "huggingface"

def main():
    parser = argparse.ArgumentParser(description="Upload dataset to Hugging Face Hub")
    parser.add_argument("--repo-id", default="AaradhyaDT/Xtreme-Bench", help="Target Hugging Face repo ID (default: AaradhyaDT/Xtreme-Bench)")
    parser.add_argument("--token", default=os.getenv("HF_TOKEN"), help="Hugging Face API token (defaults to HF_TOKEN env var)")
    parser.add_argument("--private", action="store_true", help="Create as a private dataset")
    args = parser.parse_args()

    token = args.token
    if not token:
        token = os.getenv("HUGGING_FACE_HUB_TOKEN")

    if not token:
        print("[ERROR] Hugging Face token not found!")
        print("Please provide --token <YOUR_HF_TOKEN> or set the HF_TOKEN environment variable.")
        print("You can get a write token at: https://huggingface.co/settings/tokens")
        sys.exit(1)

    api = HfApi(token=token)

    try:
        user_info = api.whoami()
        print(f"[AUTH] Authenticated as: {user_info['name']}")
    except Exception as e:
        print(f"[ERROR] Failed to authenticate with Hugging Face: {e}")
        sys.exit(1)

    repo_id = args.repo_id
    if "/" not in repo_id:
        repo_id = f"{user_info['name']}/{repo_id}"

    print(f"[REPO] Creating/verifying repository: {repo_id}...")
    create_repo(
        repo_id=repo_id,
        repo_type="dataset",
        private=args.private,
        exist_ok=True,
        token=token
    )

    print(f"[UPLOAD] Uploading folder {HF_DIR} to {repo_id}...")
    api.upload_folder(
        folder_path=str(HF_DIR),
        repo_id=repo_id,
        repo_type="dataset",
        commit_message="feat: publish Xtreme-Bench competitive programming reasoning dataset",
        token=token
    )

    print(f"\\n[SUCCESS] Dataset successfully published to: https://huggingface.co/datasets/{repo_id}")

if __name__ == "__main__":
    main()
'''
    with open(uploader_path, "w", encoding="utf-8") as f:
        f.write(uploader_code)
    print(f"Generated uploader script at {uploader_path}")


if __name__ == "__main__":
    main()
