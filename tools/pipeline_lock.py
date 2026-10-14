"""One pipeline at a time: the moulinette, auto_match and the Qwen autopilot all rewrite delinks.txt, rebuild the ROM
and commit. Running two of them at once would mix their changes, so each one takes this lock first.

    from pipeline_lock import pipeline_lock
    with pipeline_lock("moulinette"):
        ...

A lock left by a process that no longer exists is ignored. A process already holding the lock (e.g. auto_match
started by the moulinette) can take it again.
"""

import json
import os
import sys
from contextlib import contextmanager
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOCK = ROOT / "build" / "pipeline.lock"


def _alive(pid: int) -> bool:
    try:
        import psutil
        return psutil.pid_exists(pid)
    except ImportError:
        return True  # cannot check: assume it is still running


@contextmanager
def pipeline_lock(owner: str, root: Path | None = None):
    if {"-h", "--help"} & set(sys.argv[1:]):
        yield  # printing the help changes nothing: no need to wait for a running pipeline
        return
    lock = (root / "build" / "pipeline.lock") if root else LOCK  # one lock per game
    lock.parent.mkdir(parents=True, exist_ok=True)
    held_by_parent = False
    if lock.exists():
        try:
            info = json.loads(lock.read_text())
        except ValueError:
            info = {}
        pid = int(info.get("pid", 0))
        if pid in (os.getpid(), os.getppid()) or str(pid) == os.environ.get("PIPELINE_LOCK_PID"):
            held_by_parent = True
        elif pid and _alive(pid):
            raise SystemExit(f"{info.get('owner', 'another tool')} (PID {pid}) is already running: wait for it to "
                             f"finish. If it crashed, delete {lock}.")
    if not held_by_parent:
        lock.write_text(json.dumps({"pid": os.getpid(), "owner": owner}))
        os.environ["PIPELINE_LOCK_PID"] = str(os.getpid())  # inherited by the tools this process starts
    try:
        yield
    finally:
        if not held_by_parent:
            lock.unlink(missing_ok=True)
