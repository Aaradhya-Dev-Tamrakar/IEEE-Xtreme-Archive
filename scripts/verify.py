#!/usr/bin/env python3
"""
scripts/verify.py - Deterministic Verification Gate for IEEE-Xtreme-Archive
Verifies archive ledgers, dataset JSONs, sync scripts, SHA invariants, and workflows.
"""

import json
import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

def check_structure():
    print("[1/4] Checking project structure and core archive files...")
    required = [
        "README.md",
        "sync.ps1",
        "sync.bat",
        "ledger/tasks_index.json",
        "ledger/jobs_queue.json",
        "ledger/archive_ledger.json",
    ]
    missing = [f for f in required if not (ROOT / f).exists()]
    if missing:
        print(f"[FAIL] Missing required files: {missing}")
        return False
    print("  [PASS] All core project files, ledgers, and sync wrappers exist.")
    return True

def check_ledger_json():
    print("[2/4] Verifying JSON integrity across ledgers and datasets...")
    json_files = list((ROOT / "ledger").glob("*.json"))
    for jf in json_files:
        try:
            with open(jf, "r", encoding="utf-8") as f:
                json.load(f)
        except Exception as e:
            print(f"[FAIL] Invalid JSON in {jf.relative_to(ROOT)}: {e}")
            return False
    print(f"  [PASS] Successfully parsed {len(json_files)} ledger JSON documents.")
    return True

def check_synthetic_shas():
    print("[3/4] Enforcing zero synthetic commit SHAs...")
    synthetic_pattern = re.compile(r'\b(rel\d+|upg\d+|xtool\d+|dummy_sha|fake_sha|placeholder_sha)\b', re.IGNORECASE)
    text_extensions = {".md", ".json", ".yml", ".yaml", ".ps1", ".bat", ".py", ".mjs"}
    
    violations = []
    for file in ROOT.rglob("*"):
        if file.is_file() and file.suffix.lower() in text_extensions:
            if any(part in file.parts for part in (".git", "__pycache__", "scripts")):
                continue
            try:
                content = file.read_text(encoding="utf-8", errors="ignore")
                for line_idx, line in enumerate(content.splitlines(), start=1):
                    if synthetic_pattern.search(line):
                        violations.append(f"{file.relative_to(ROOT)}:{line_idx} - {line.strip()}")
            except Exception:
                pass

    if violations:
        print(f"[FAIL] Found {len(violations)} synthetic SHA violations:")
        for v in violations[:10]:
            print(f"  {v}")
        return False
    print("  [PASS] Zero synthetic commit SHAs detected.")
    return True

def check_workflows():
    print("[4/4] Verifying GitHub workflows...")
    wf_dir = ROOT / ".github" / "workflows"
    if not wf_dir.exists():
        print("[FAIL] Missing .github/workflows directory.")
        return False
    workflows = list(wf_dir.glob("*.yml")) + list(wf_dir.glob("*.yaml"))
    if not workflows:
        print("[FAIL] No workflow files found in .github/workflows.")
        return False
    print(f"  [PASS] Verified {len(workflows)} CI workflow definitions.")
    return True

def main():
    print(f"Running deterministic verification in {ROOT}\n")
    checks = [
        check_structure,
        check_ledger_json,
        check_synthetic_shas,
        check_workflows,
    ]
    
    passed = 0
    errors = 0
    for check in checks:
        if check():
            passed += 1
        else:
            errors += 1
        print()
        
    print("=" * 50)
    print(f"Passed: {passed}   Errors: {errors}")
    if errors == 0:
        print("\nALL CHECKS PASSED DETERMINISTICALLY.")
        return 0
    else:
        print(f"\nVERIFICATION FAILED WITH {errors} ERROR(S).")
        return 1

if __name__ == "__main__":
    sys.exit(main())
