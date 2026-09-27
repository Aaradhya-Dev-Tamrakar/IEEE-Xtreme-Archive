import re
from pathlib import Path

warehouse_file = Path("warehouse/corpus_warehouse.md")
index_map_file = Path("warehouse/index_map.md")

with open(warehouse_file, "r", encoding="utf-8") as f:
    wlines = [line.rstrip("\r\n") for line in f]

with open(index_map_file, "r", encoding="utf-8") as f:
    ilines = f.readlines()

print(f"Total lines in corpus_warehouse.md: {len(wlines):,}")

checked = 0
for line in ilines:
    m = re.search(
        r"\|\s*(\d+)\s*\|\s*`([^`]+)`\s*\|\s*\[([^\]]+)\]\(corpus_warehouse\.md#task-([^)]+)\)\s*\|\s*`\[(\d+)\]`\s*\|\s*`([^`]+)`\s*\|\s*\[`L(\d+)-L(\d+)`\]",
        line,
    )
    if m:
        checked += 1
        num, slug, title, anchor_slug, arch_id, diff, start_str, end_str = m.groups()
        start = int(start_str)
        end = int(end_str)

        # Check start line
        assert wlines[start - 1] == f'<a id="task-{slug}"></a>', f"Mismatch at start line {start}: got {wlines[start - 1]}"
        # Check title line
        assert f"## [{int(num):03d}] {title}" in wlines[start], f"Mismatch at title line {start+1}: got {wlines[start]}"
        # Check end line is delimiter or empty
        assert wlines[end - 2] == "---", f"Mismatch before end line: got {wlines[end - 2]}"

print(f"Verification passed for all {checked} table entries!")
