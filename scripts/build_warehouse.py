"""
Script to build the unified Markdown warehouse (warehouse/corpus_warehouse.md)
and the line-indexed navigation map (warehouse/index_map.md).
"""

import json
import os
import re
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parent.parent
TASKS_DIR = ROOT_DIR / "platforms" / "csacademy" / "tasks"
WAREHOUSE_DIR = ROOT_DIR / "warehouse"
TASKS_INDEX_PATH = ROOT_DIR / "ledger" / "tasks_index.json"
CATALOG_PATH = ROOT_DIR / "briefings" / "catalog.md"

ARCHETYPE_NAMES = {
    "01": "Dynamic Programming",
    "02": "Graph Theory & Network Flows",
    "03": "Trees & Lowest Common Ancestor",
    "04": "Range Queries & Data Structures",
    "05": "Combinatorics & Number Theory",
    "06": "Greedy Algorithms & Two Pointers",
    "07": "Computational Geometry & Convex Hull",
    "08": "String Algorithms",
    "09": "Game Theory & Nim Games",
    "10": "Constructive & Interactive Algorithms",
}


def load_archetype_mapping():
    mapping = {}
    if not CATALOG_PATH.exists():
        return mapping

    with open(CATALOG_PATH, "r", encoding="utf-8") as f:
        for line in f:
            line_str = line.strip()
            if line_str.startswith("|") and not line_str.startswith("| Slug") and not line_str.startswith("| :"):
                parts = [p.strip() for p in line_str.split("|")[1:-1]]
                if len(parts) >= 3:
                    slug_match = re.search(r"`([^`]+)`", parts[0])
                    arch_match = re.search(r"\[`?(\d{2})`?\]", parts[2])
                    if slug_match and arch_match:
                        slug = slug_match.group(1).strip()
                        arch_id = arch_match.group(1).strip()
                        mapping[slug] = arch_id
    return mapping


def build_warehouse():
    WAREHOUSE_DIR.mkdir(parents=True, exist_ok=True)
    arch_map = load_archetype_mapping()

    with open(TASKS_INDEX_PATH, "r", encoding="utf-8") as f:
        tasks_index = json.load(f)

    # Sort tasks alphabetically by slug for deterministic layout
    tasks_index = sorted(tasks_index, key=lambda x: x["slug"].lower())

    warehouse_file = WAREHOUSE_DIR / "corpus_warehouse.md"
    index_map_file = WAREHOUSE_DIR / "index_map.md"

    warehouse_lines = []
    task_entries = []

    # Write Warehouse Header
    header = [
        "# IEEE-Xtreme & CS Academy Master Algorithmic Corpus Warehouse",
        "",
        "> **Corpus Warehouse Metadata & Grounding Index**",
        "> - **Total Archived Tasks:** 662 Verified Problem Statements",
        "> - **Target Dedicated Notebook:** `071b19a5-960f-429c-91e4-384669bea974` (*IEEE-Xtreme Algorithmic Corpus*)",
        "> - **Companion Line-Indexed Map:** [`index_map.md`](index_map.md)",
        "> - **Primary Repository:** `F:\\Aaradhya-Dev-Tamrakar\\IEEE-Xtreme-Archive`",
        "> - **Mathematical Notation:** Full KaTeX LaTeX math preserved verbatim ($formula$ and $$display$$)",
        "> - **Navigation Anchor Pattern:** `<a id=\"task-<slug>\"></a>`",
        "",
        "---",
        "",
    ]
    warehouse_lines.extend(header)

    task_count = 0
    for task_meta in tasks_index:
        slug = task_meta["slug"]
        task_dir = TASKS_DIR / slug
        statement_path = task_dir / "statement.md"

        if not statement_path.exists():
            continue

        task_count += 1
        problem_json_path = task_dir / "problem.json"
        time_limit = "N/A"
        memory_limit = "N/A"
        contest = task_meta.get("contest") or "CS Academy Archive"
        difficulty = task_meta.get("difficulty") or "UNKNOWN"
        title = task_meta.get("title") or slug

        if problem_json_path.exists():
            try:
                with open(problem_json_path, "r", encoding="utf-8") as pf:
                    pdata = json.load(pf)
                    time_limit = pdata.get("time_limit", time_limit)
                    memory_limit = pdata.get("memory_limit", memory_limit)
                    if pdata.get("contest"):
                        contest = pdata.get("contest")
                    if pdata.get("difficulty"):
                        difficulty = pdata.get("difficulty")
                    if pdata.get("title"):
                        title = pdata.get("title")
            except Exception:
                pass

        arch_id = arch_map.get(slug, "06")
        arch_name = ARCHETYPE_NAMES.get(arch_id, "Algorithmic Problem")

        with open(statement_path, "r", encoding="utf-8") as sf:
            statement_content = sf.read().strip()

        # Record start line (1-indexed)
        start_line = len(warehouse_lines) + 1

        task_header_block = [
            f'<a id="task-{slug}"></a>',
            f"## [{task_count:03d}] {title} (`{slug}`)",
            "",
            f"- **Archetype:** `[{arch_id}]` {arch_name}",
            f"- **Difficulty:** `{difficulty}`",
            f"- **Contest:** {contest}",
            f"- **Time Limit:** `{time_limit}` | **Memory Limit:** `{memory_limit}`",
            f"- **Official URL:** [{task_meta.get('url', 'CS Academy')}]({task_meta.get('url', '')})",
            f"- **Repository Source:** [`platforms/csacademy/tasks/{slug}/`](../platforms/csacademy/tasks/{slug}/)",
            "",
            "### Problem Statement",
            "",
        ]

        warehouse_lines.extend(task_header_block)
        # Split statement content by lines to maintain exact 1:1 line counting
        statement_lines = statement_content.splitlines()
        warehouse_lines.extend(statement_lines)
        warehouse_lines.extend([
            "",
            "---",
            "",
        ])
        end_line = len(warehouse_lines)

        task_entries.append({
            "num": task_count,
            "slug": slug,
            "title": title,
            "arch_id": arch_id,
            "arch_name": arch_name,
            "difficulty": difficulty,
            "contest": contest,
            "time_limit": time_limit,
            "memory_limit": memory_limit,
            "start_line": start_line,
            "end_line": end_line,
            "line_count": end_line - start_line + 1,
            "url": task_meta.get("url", ""),
        })

    # Write warehouse file
    full_warehouse_text = "\n".join(warehouse_lines) + "\n"
    with open(warehouse_file, "w", encoding="utf-8") as wf:
        wf.write(full_warehouse_text)

    total_warehouse_lines = len(warehouse_lines)
    file_size_mb = len(full_warehouse_text.encode("utf-8")) / (1024 * 1024)
    word_count = len(full_warehouse_text.split())

    # Build Index Map
    index_lines = [
        "# IEEE-Xtreme Algorithmic Corpus: Master Line-Indexed Navigation Map",
        "",
        "> **Warehouse Navigation Matrix & Oracle Line Index**",
        f"> - **Master Warehouse File:** [`corpus_warehouse.md`](corpus_warehouse.md) ({total_warehouse_lines:,} lines, {file_size_mb:.2f} MB, {word_count:,} words)",
        f"> - **Total Cataloged Problem Statements:** {len(task_entries)}",
        "> - **Target NotebookLM Notebook:** `071b19a5-960f-429c-91e4-384669bea974` (*IEEE-Xtreme Algorithmic Corpus*)",
        "> - **Google Drive Folder ID:** `1DrXUosZl3_Ihh8Ud2ZTW83aL6g7NA-iu`",
        "",
        "## 1. Quick Archetype Index",
        "",
        "| ID | Archetype Name | Task Count | Warehouse Line Ranges | Section |",
        "| :-: | :--- | :-: | :--- | :--- |",
    ]

    # Archetype statistics
    arch_tasks = {}
    for entry in task_entries:
        arch_tasks.setdefault(entry["arch_id"], []).append(entry)

    for aid in sorted(ARCHETYPE_NAMES.keys()):
        aname = ARCHETYPE_NAMES[aid]
        tasks = arch_tasks.get(aid, [])
        if tasks:
            min_l = min(t["start_line"] for t in tasks)
            max_l = max(t["end_line"] for t in tasks)
            line_span = f"L{min_l:,} - L{max_l:,}"
        else:
            line_span = "N/A"
        index_lines.append(f"| `{aid}` | **{aname}** | {len(tasks)} | `{line_span}` | [Jump to Archetype {aid}](#archetype-{aid}-{aname.lower().replace(' ', '-').replace('&', 'and')}) |")

    index_lines.extend([
        "",
        "---",
        "",
        "## 2. Master Sequential Line Lookup (All 662 Problems)",
        "",
        "Use this table to look up any task by slug, title, or exact line range inside [`corpus_warehouse.md`](corpus_warehouse.md). Click on any line range or task anchor to jump directly.",
        "",
        "| # | Slug | Title | Archetype | Difficulty | Warehouse Line Range | Lines | Contest | Local Source |",
        "| :-: | :--- | :--- | :-: | :-: | :---: | :-: | :--- | :---: |",
    ])

    for t in task_entries:
        line_link = f"[`L{t['start_line']}-L{t['end_line']}`](corpus_warehouse.md#L{t['start_line']}-L{t['end_line']})"
        anchor_link = f"[{t['title']}](corpus_warehouse.md#task-{t['slug']})"
        arch_badge = f"`[{t['arch_id']}]`"
        task_dir_link = f"[`files`](../platforms/csacademy/tasks/{t['slug']}/)"
        index_lines.append(
            f"| {t['num']} | `{t['slug']}` | {anchor_link} | {arch_badge} | `{t['difficulty']}` | {line_link} | {t['line_count']} | {t['contest']} | {task_dir_link} |"
        )

    # Detailed Archetype Subsections
    index_lines.extend([
        "",
        "---",
        "",
        "## 3. Archetype Breakdowns & Task Rosters",
        "",
    ])

    for aid in sorted(ARCHETYPE_NAMES.keys()):
        aname = ARCHETYPE_NAMES[aid]
        tasks = arch_tasks.get(aid, [])
        slug_anchor = f"archetype-{aid}-{aname.lower().replace(' ', '-').replace('&', 'and')}"
        index_lines.extend([
            f"<a id=\"{slug_anchor}\"></a>",
            f"### Archetype {aid}: {aname} ({len(tasks)} Tasks)",
            "",
            f"Study Guide: [`briefings/{aid}_{aname.lower().replace(' ', '_').replace('&', 'and')}.md`](../briefings/{aid}_{aname.lower().replace(' ', '_').replace('&', 'and')}.md)",
            "",
            "| # | Slug | Title | Difficulty | Warehouse Line Range | Contest |",
            "| :-: | :--- | :--- | :-: | :---: | :--- |",
        ])

        for t in tasks:
            line_link = f"[`L{t['start_line']}-L{t['end_line']}`](corpus_warehouse.md#L{t['start_line']}-L{t['end_line']})"
            anchor_link = f"[{t['title']}](corpus_warehouse.md#task-{t['slug']})"
            index_lines.append(f"| {t['num']} | `{t['slug']}` | {anchor_link} | `{t['difficulty']}` | {line_link} | {t['contest']} |")

        index_lines.extend(["", "---", ""])

    # Write index map file
    with open(index_map_file, "w", encoding="utf-8") as imf:
        imf.write("\n".join(index_lines) + "\n")

    print(f"Successfully generated:")
    print(f"  - {warehouse_file} ({total_warehouse_lines:,} lines, {file_size_mb:.2f} MB, {word_count:,} words)")
    print(f"  - {index_map_file} ({len(index_lines):,} lines, {len(task_entries)} mapped problems)")


if __name__ == "__main__":
    build_warehouse()
