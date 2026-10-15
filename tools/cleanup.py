#!/usr/bin/env python3
"""Cleans the C written by m2c (src/auto/ and the files tools/regroup.py made from them) without changing the code.

    python tools/cleanup.py              # clean, clang-format, check that the ROM still rebuilds
    python tools/cleanup.py --dry-run    # only count what would change

What it changes (nothing here can change what the compiler emits):
  - m2c's notes after declarations: /* extern */, /* inferred */, /* irregular */, /* compiler-managed */;
  - runs of blank lines;
  - the formatting (clang-format, like the CI of the game repos).
The ROM is rebuilt at the end all the same (configure + ninja), and every file is put back if it does not match.
Changes that can change the code (real prototypes from the SDK headers instead of m2c's guesses, struct fields
instead of M2C_FIELD offsets) belong in a verified pass: each file compiled and compared with the ROM
(regroup.compile_check) before it is kept.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import find_culprits as fc  # noqa: E402
from pipeline_lock import journal_begin, journal_end  # noqa: E402

NOTE = re.compile(r"[ \t]*/\* (?:extern|inferred|irregular|compiler-managed|unused)(?: [^*]*)? \*/")
BLANKS = re.compile(r"\n{3,}")


def clean(text: str) -> str:
    text = NOTE.sub("", text)
    text = re.sub(r"[ \t]+$", "", text, flags=re.M)
    return BLANKS.sub("\n\n", text).strip() + "\n"


def m2c_files() -> list[Path]:
    return [p for p in (ROOT / "src").rglob("*.c") if '#include "m2c.h"' in p.read_text(encoding="utf-8", errors="replace")]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true", help="Only count the files that would change")
    args = ap.parse_args()
    changed = {}
    for p in m2c_files():
        t = p.read_text(encoding="utf-8", errors="surrogateescape")
        n = clean(t)
        if n != t:
            changed[p] = (t, n)
    print(f"{len(changed)} files to clean")
    if args.dry_run or not changed:
        return
    journal_begin(list(changed))
    for p, (_t, n) in changed.items():
        p.write_text(n, encoding="utf-8", errors="surrogateescape", newline="\n")
    rels = [p.relative_to(ROOT).as_posix() for p in changed]
    try:
        for k in range(0, len(rels), 200):
            subprocess.run(["pre-commit", "run", "clang-format", "--files", *rels[k:k + 200]], cwd=ROOT,
                           capture_output=True)
    except OSError:
        print("pre-commit not found: files left unformatted")
    print("Rebuilding the ROM...", flush=True)
    out = fc.build()
    if not fc.rom_ok(out):
        for p, (t, _n) in changed.items():
            p.write_text(t, encoding="utf-8", errors="surrogateescape", newline="")
        journal_end()
        print("The ROM does not rebuild: every file was put back.")
        print("\n".join(out.splitlines()[-20:]))
        sys.exit(1)
    journal_end()
    print(f"OK: {len(changed)} files cleaned, ROM identical. Run `python tools/match.py verify` before committing.")


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    if "--dry-run" in sys.argv:
        main()
    else:
        with pipeline_lock("cleanup"):
            main()
