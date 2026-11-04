"""One pipeline at a time: the moulinette, auto_match and the Qwen autopilot all rewrite delinks.txt, rebuild the ROM
and commit. Running two of them at once would mix their changes, so each one takes this lock first.

    from pipeline_lock import pipeline_lock
    with pipeline_lock("moulinette"):
        ...

A lock left by a process that no longer exists is ignored. A process already holding the lock (e.g. auto_match
started by the moulinette) can take it again.

The journal makes an integration undoable when the process is killed (a job cancelled in the studio, Ctrl+C):

    journal_begin([DELINKS, COMPILERS_TXT])   # copies of the files about to change
    journal_created(new_source_files)         # files to delete if the run does not finish
    ...
    journal_end()                             # finished (kept or rolled back): nothing to undo

A journal left by a killed run is undone by the next pipeline_lock (or `recover()`): the copies are written back
and the new files deleted, so the game is never left with half-verified files declared complete.
"""

import base64
import json
import os
import sys
import time
from contextlib import contextmanager
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import ROOT  # noqa: E402  (the game, also when this runs from studio/gametools: one lock per game)

LOCK = ROOT / "build" / "pipeline.lock"
JOURNAL = ROOT / "build" / "pipeline.journal.json"


def _write_journal(data: dict) -> None:
    JOURNAL.parent.mkdir(parents=True, exist_ok=True)
    tmp = JOURNAL.with_suffix(".tmp")
    tmp.write_text(json.dumps(data), encoding="utf-8")
    os.replace(tmp, JOURNAL)  # never a half-written journal


def journal_begin(paths: list[Path]) -> None:
    """Keeps a copy of `paths` until journal_end(). Files that do not exist yet are deleted on recovery."""
    saved = {str(Path(p).resolve()): base64.b64encode(Path(p).read_bytes()).decode() if Path(p).exists() else None
             for p in paths}
    if JOURNAL.exists():  # nested step of the same run: keep the oldest copies
        data = json.loads(JOURNAL.read_text(encoding="utf-8"))
        for k, v in saved.items():
            data["saved"].setdefault(k, v)
    else:
        data = {"pid": os.getpid(), "saved": saved, "created": []}
    _write_journal(data)


def journal_created(paths) -> None:
    if not JOURNAL.exists():
        return
    data = json.loads(JOURNAL.read_text(encoding="utf-8"))
    data["created"] += [str(Path(p).resolve()) for p in paths]
    _write_journal(data)


def journal_end() -> None:
    JOURNAL.unlink(missing_ok=True)


def recover(log=print, holding_lock: bool = False) -> bool:
    """Undoes the integration of a run that was killed. Returns True if there was one. Without the lock, nothing is
    done while a pipeline is running (its journal is not stale)."""
    if not JOURNAL.exists():
        return False
    if not holding_lock and LOCK.exists():
        try:
            if _alive(int(json.loads(LOCK.read_text()).get("pid", 0))):
                return False
        except ValueError:
            pass
    try:
        data = json.loads(JOURNAL.read_text(encoding="utf-8"))
    except ValueError:
        JOURNAL.unlink(missing_ok=True)
        return False
    for path, content in data.get("saved", {}).items():
        if content is None:
            Path(path).unlink(missing_ok=True)
        else:
            Path(path).write_bytes(base64.b64decode(content))
    for path in data.get("created", []):
        Path(path).unlink(missing_ok=True)
    JOURNAL.unlink(missing_ok=True)
    log(f"A previous run was interrupted: restored {len(data.get('saved', {}))} file(s), removed "
        f"{len(data.get('created', []))} unverified source file(s).")
    return True


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
    held_by_parent = _acquire(lock, owner)
    if not held_by_parent:
        os.environ["PIPELINE_LOCK_PID"] = str(os.getpid())  # inherited by the tools this process starts
        if root is None:
            recover(holding_lock=True)
    try:
        yield
    finally:
        if not held_by_parent and (lock_owner(lock) or {}).get("pid") == os.getpid():
            lock.unlink(missing_ok=True)  # never someone else's lock


def lock_owner(lock: Path = LOCK) -> dict | None:
    """{"pid", "owner"} of the lock file, None when there is none or it cannot be read (being written)."""
    try:
        info = json.loads(lock.read_text())
        return info if isinstance(info, dict) else None
    except (OSError, ValueError):
        return None


def held(lock: Path = LOCK) -> dict | None:
    """The owner of the lock when a live process holds it (for the Studio's scheduler), else None."""
    info = lock_owner(lock)
    pid = int((info or {}).get("pid", 0) or 0)
    return info if pid and _alive(pid) else None


def _acquire(lock: Path, owner: str) -> bool:
    """Creates the lock file atomically (O_CREAT | O_EXCL: of two tools starting together only one gets it).
    Returns True when an ancestor of this process already holds it (nothing created)."""
    me = json.dumps({"pid": os.getpid(), "owner": owner})
    for _ in range(100):
        try:
            fd = os.open(lock, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
        except FileExistsError:
            info = lock_owner(lock)
            if info is None:  # just created by another tool, not written yet; or a broken file left by a crash
                try:
                    age = time.time() - lock.stat().st_mtime
                except OSError:
                    continue  # removed meanwhile: try again
                if age < 10:
                    time.sleep(0.2)
                    continue
                lock.unlink(missing_ok=True)
                continue
            pid = int(info.get("pid", 0) or 0)
            if pid in (os.getpid(), os.getppid()) or str(pid) == os.environ.get("PIPELINE_LOCK_PID"):
                return True
            if pid and _alive(pid):
                raise SystemExit(f"{info.get('owner', 'another tool')} (PID {pid}) is already running: wait for it "
                                 f"to finish. If it crashed, delete {lock}.")
            lock.unlink(missing_ok=True)  # left by a process that no longer exists
            continue
        with os.fdopen(fd, "w") as f:
            f.write(me)
        # Two tools that removed the same stale lock at once: the second one may have deleted the first one's new
        # lock. Whoever no longer reads its own pid backs off
        time.sleep(0.05)
        info = lock_owner(lock)
        if (info or {}).get("pid") != os.getpid():
            raise SystemExit(f"{(info or {}).get('owner', 'another tool')} took the pipeline lock at the same time: "
                             "try again later.")
        return False
    raise SystemExit(f"Cannot take {lock}: delete it if no tool is running.")
