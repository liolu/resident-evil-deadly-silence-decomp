#!/usr/bin/env python3
"""Which part of the game a function belongs to, and what it calls: the context given to the AIs (Qwen, Claude)
with each function, so they know whether they read Nintendo's SDK, the C library or the game's engine.

    python tools/codemap.py <function>...      # print the context of these functions
    python tools/codemap.py --summary          # how many functions of the main module in each part

Parts, from the most to the least certain:
  1. the function has a real name (tools/names.py) found in the donor database (`decomp ds/donors.sqlite`):
     its original file says the library and module: NitroSDK os (os_thread.c), NitroSystem snd, MSL...;
  2. it loads the name of a source file (an assert: "Brain.c"): that file of the game;
  3. it sits between functions of the same library (libraries are linked in one piece): probably that library;
  4. else it is game code, described by the first paragraph of docs/engine.md when the game has one (engine,
     language), or by the `engine` argument (the Studio passes the developer's name).
The calls (bl) and callers come from the disassembly (build/<version>/asm, `ninja dis`), with the part of each.
"""
import argparse
import bisect
import collections
import re
import sqlite3
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import regroup  # noqa: E402

LIBS = {
    "nitro": "NitroSDK (Nintendo's DS system library, C)",
    "nnsys": "NitroSystem (Nintendo's middleware: sound, 2D/3D graphics, heaps; C)",
    "wifi": "NitroWiFi (Nintendo's network library)",
    "dwc": "NitroDWC (Nintendo Wi-Fi Connection)",
    "vct": "libvct (Nintendo's voice chat library)",
    "msl": "MSL (Metrowerks' standard C library and runtime)",
    "lib": "a third-party library",
}
SRC_FILE = re.compile(rb"^[\w./\\:-]{1,60}\.(?:c|cpp|cc|h)$", re.I)
FUNC_RE = re.compile(r"^(\S+) kind:function\((arm|thumb),size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)", re.M)


def _library(path: str) -> tuple[str, str]:
    """('nitro', 'os') from src/nitro/os/os_thread.c"""
    parts = path.split("/")
    lib = parts[1] if len(parts) > 2 else "lib"
    module = parts[2] if len(parts) > 3 else ""
    return lib, module


class CodeMap:
    def __init__(self, engine: str = ""):
        self.funcs = sorted((int(a, 16), int(s, 16), n, mode)
                            for n, mode, s, a in FUNC_RE.findall(project.SYMBOLS.read_text(encoding="utf-8")))
        self.by_name = {n: (a, s, mode) for a, s, n, mode in self.funcs}
        self.addrs = [f[0] for f in self.funcs]
        self.engine = self._engine() or engine
        self.origin = {}  # name -> original file (src/nitro/os/os_thread.c)
        try:
            con = sqlite3.connect(regroup.DB, timeout=60)
            for a, s, n, mode in self.funcs:
                if not n.startswith("func_"):
                    f = regroup.original_file(con, n)
                    if f:
                        self.origin[n] = f
        except sqlite3.Error:
            pass
        self.asserted = self._assert_files()
        self._asm = None

    # ------------------------------------------------------------ parts

    @staticmethod
    def _engine() -> str:
        doc = ROOT / "docs" / "engine.md"
        if not doc.exists():
            return ""
        paras = [p for p in doc.read_text(encoding="utf-8", errors="replace").split("\n\n")
                 if p.strip() and not p.lstrip().startswith(("#", "|", "-", "```"))]
        text = re.sub(r"[*`]", "", " ".join(paras[0].split())) if paras else ""
        return text[:500].rstrip(". ")

    def _assert_files(self) -> dict[str, str]:
        """{function: source file name} for the functions that load a source file name (assert messages)."""
        ex = project.EXTRACT / "arm9"
        try:
            import find_culprits as fc
            data = (ex / "arm9.bin").read_bytes()
            base = fc.base_address(ex / "arm9.yaml")
        except OSError:
            return {}
        if base is None:
            return {}
        import donorlib
        out = {}
        for a, s, n, mode in self.funcs:
            if mode != "arm" or not base <= a < base + len(data):
                continue
            code = data[a - base: a - base + s - s % 4]
            words = struct.unpack(f"<{len(code) // 4}I", code)
            for i in donorlib.pool_words(words):
                if i < len(words) and base <= words[i] < base + len(data):
                    o = words[i] - base
                    end = data.find(b"\0", o, o + 64)
                    if end > o and SRC_FILE.match(data[o:end]):
                        out[n] = data[o:end].decode("ascii").replace("\\", "/").split("/")[-1]
        return out

    def part(self, name: str) -> str:
        if name in self.origin:
            lib, module = _library(self.origin[name])
            where = f", module {module}" if module else ""
            return f"{LIBS.get(lib, LIBS['lib'])}{where}, original file {Path(self.origin[name]).name}"
        if name in self.asserted:
            return f"game code, source file {self.asserted[name]} (named in an assert)" + \
                (f"; engine: {self.engine}" if self.engine else "")
        guess = self._between(name)
        if guess:
            return guess
        return "game code" + (f"; engine: {self.engine}" if self.engine else "")

    def _between(self, name: str) -> str:
        """Libraries are linked in one piece: an unnamed function between two functions of the same library
        (at most 8 functions away on each side) most likely belongs to it."""
        if name not in self.by_name:
            return ""
        i = bisect.bisect_left(self.addrs, self.by_name[name][0])

        def side(rng):
            for j in rng:
                n = self.funcs[j][2]
                if n in self.origin:
                    return n, _library(self.origin[n])
            return None, None

        before, lb = side(range(i - 1, max(-1, i - 9), -1))
        after, la = side(range(i + 1, min(len(self.funcs), i + 9)))
        if lb and la and lb[0] == la[0]:
            module = f", module {lb[1]}" if lb[1] == la[1] and lb[1] else ""
            return f"probably {LIBS.get(lb[0], LIBS['lib'])}{module} (between {before} and {after})"
        return ""

    # ------------------------------------------------------------ calls

    def _load_asm(self) -> dict[str, str]:
        """{function: [called functions]} read line by line from build/<version>/asm."""
        if self._asm is None:
            self._asm = {}
            self._callers = collections.defaultdict(set)
            start = re.compile(r"^\s+(?:arm|thumb)_func_start (\w+)")
            call = re.compile(r"\sblx?\s+(\w+)")
            for f in sorted(project.ASM_DIR.rglob("*.s")) if project.ASM_DIR.exists() else []:
                cur = None
                for line in f.read_text(encoding="utf-8", errors="replace").splitlines():
                    m = start.match(line)
                    if m:
                        cur = self._asm.setdefault(m.group(1), [])
                        caller = m.group(1)
                        continue
                    if cur is not None and " bl" in line:
                        m = call.search(line)
                        if m:
                            cur.append(m.group(1))
                            self._callers[m.group(1)].add(caller)
        return self._asm

    def callees(self, name: str) -> list[str]:
        return list(dict.fromkeys(c for c in self._load_asm().get(name, []) if c != name))

    def callers(self, name: str) -> list[str]:
        self._load_asm()
        return sorted(self._callers.get(name, ()))

    def short(self, name: str) -> str:
        """Part of a called function, in a few words."""
        if name in self.origin:
            lib, module = _library(self.origin[name])
            return {"nitro": "NitroSDK", "nnsys": "NitroSystem", "msl": "C library"}.get(lib, lib) + \
                (f" {module}" if module else "")
        if name in self.asserted:
            return self.asserted[name]
        if name.startswith("func_"):
            return "game" if not self._between(name) else "probably " + self._between(name).split(" (")[0][9:]
        return "named"

    def context(self, name: str, max_calls: int = 12) -> str:
        """The text given to an AI before the code of `name`."""
        lines = [f"Function {name}: {self.part(name)}."]
        calls = self.callees(name)
        if calls:
            shown = ", ".join(f"{c} ({self.short(c)})" for c in calls[:max_calls])
            lines.append(f"It calls: {shown}{' ...' if len(calls) > max_calls else ''}.")
        callers = self.callers(name)
        if callers:
            shown = ", ".join(f"{c} ({self.short(c)})" for c in callers[:6])
            lines.append(f"Called by: {shown}{' ...' if len(callers) > 6 else ''}.")
        unnamed = sum(1 for c in calls if c.startswith("func_"))
        if calls and unnamed < len(calls):
            lines.append("Named functions are real names (NitroSDK / NitroSystem / C library): use them to guess "
                         "what the code does and which types it uses; func_XXXXXXXX are not named yet.")
        return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("names", nargs="*")
    ap.add_argument("--summary", action="store_true")
    a = ap.parse_args()
    cm = CodeMap()
    if a.summary:
        c = collections.Counter()
        for addr, size, n, _m in cm.funcs:
            if project.MAIN_TEXT[0] <= addr < project.MAIN_TEXT[1]:
                p = cm.part(n)
                key = p.split(",")[0].split(";")[0].split(" (")[0]
                c[key] += 1
        for k, v in c.most_common():
            print(f"{v:6}  {k}")
        return
    for n in a.names:
        print(cm.context(n) + "\n")


if __name__ == "__main__":
    main()
