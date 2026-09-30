#!/usr/bin/env python3
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

def load_dotenv(env_path: Path):
    if not env_path.exists():
        return
    try:
        with open(env_path, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if "=" in line:
                    k, v = line.split("=", 1)
                    k = k.strip()
                    v = v.strip().strip("'\"")
                    if k and k not in os.environ:
                        os.environ[k] = v
    except Exception:
        pass

def main():
    load_dotenv(ROOT / ".env")
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

    print(f"\n[SUCCESS] Dataset successfully published to: https://huggingface.co/datasets/{repo_id}")

if __name__ == "__main__":
    main()
