#!/usr/bin/env python3
"""Automated build and test runner invoked by the boundary-test-gen Agent Skill."""
import subprocess
import sys
from pathlib import Path

def run_cmd(cmd, cwd):
    print(f"[SKILL-RUNNER] Executing: {' '.join(cmd)}")
    result = subprocess.run(cmd, cwd=cwd, text=True, capture_output=True)
    if result.stdout:
        print(result.stdout)
    if result.stderr:
        print(result.stderr, file=sys.stderr)
    return result.returncode

def main():
    # Resolves from .agents/skills/boundary-test-gen/scripts/run_tests.py -> repo root
    repo_root = Path(__file__).resolve().parents[4]
    build_dir = repo_root / "build"
    build_dir.mkdir(exist_ok=True)

    if run_cmd(["cmake", ".."], cwd=build_dir) != 0:
        sys.exit(1)
    if run_cmd(["cmake", "--build", "."], cwd=build_dir) != 0:
        sys.exit(1)
    if run_cmd(["ctest", "--output-on-failure"], cwd=build_dir) != 0:
        sys.exit(1)

    print("\n=== [SKILL-RUNNER] ALL TESTS PASSED ===")

if __name__ == "__main__":
    main()