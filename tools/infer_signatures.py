#!/usr/bin/env python3
"""Guesses the signature of every function from the disassembly (build/usa/asm), for the m2c context.

- Arguments: registers r0-r3 read before being written, scanning the function from its start up to the
  first call or return (straight-line approximation).
- Return value: at least one caller reads r0 after `bl` before writing it.

Types are unknown, so every value is `M2C_UNK`. Used by tools/gen_context.py for functions that have no
real prototype yet.
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ASM_DIR = ROOT / "build" / "usa" / "asm"
ARGS = ["r0", "r1", "r2", "r3"]
WRITES_FIRST = re.compile(r"^(mov|mvn|add|sub|rsb|and|orr|eor|bic|lsl|lsr|asr|ror|mul|ldr\w*|adr)s?\w*$")
NO_WRITE = re.compile(r"^(cmp|cmn|tst|teq|str\w*|push|pop|b|bx|blx|bl|stm\w*)$")


def operands(line: str) -> tuple[str, list[str]]:
    parts = line.strip().split(None, 1)
    if not parts:
        return "", []
    return parts[0], re.findall(r"\b(r\d+|ip|lr|sp|pc)\b", parts[1] if len(parts) > 1 else "")


def count_args(body: list[str]) -> int:
    written, read = set(), set()
    for line in body:
        mnem, regs = operands(line)
        if not mnem or line.strip().startswith((".", ";")) or line.rstrip().endswith(":"):
            continue
        base = re.sub(r"(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)$", "", mnem)
        if base.startswith(("bl", "bx", "b")) and base in ("bl", "blx", "bx", "b") or mnem.startswith("pop"):
            break
        if base.startswith("push"):
            continue  # saves registers (r3 only pads the stack): not a use of an argument
        if base.startswith("stm") or NO_WRITE.match(base):
            srcs, dsts = regs, []
        elif base.startswith("ldm"):
            srcs, dsts = regs[:1], regs[1:]
        else:
            srcs, dsts = regs[1:], regs[:1]
        for r in srcs:
            if r in ARGS and r not in written:
                read.add(r)
        written.update(dsts)
    return max((ARGS.index(r) + 1 for r in read), default=0)


def functions() -> dict[str, list[str]]:
    out = {}
    for f in ASM_DIR.glob("*.s"):
        for m in re.finditer(r"^(\w+): ; 0x[0-9a-f]+\n(.*?)^\s+arm_func_end \1$", f.read_text(encoding="utf-8"),
                             re.M | re.S):
            out[m.group(1)] = m.group(2).splitlines()
    return out


def call_sites(funcs: dict[str, list[str]]) -> dict[str, list[list[str]]]:
    """For every callee, the instructions that follow each `bl` to it."""
    sites = {}
    for body in funcs.values():
        for i, line in enumerate(body):
            m = re.match(r"^\s+bl (\w+)$", line)
            if m:
                sites.setdefault(m.group(1), []).append(body[i + 1:i + 6])
    return sites


def returns_value(after_calls: list[list[str]]) -> bool:
    for following in after_calls:
        for nxt in following:
            mnem, regs = operands(nxt)
            if not mnem or nxt.rstrip().endswith(":") or mnem.startswith("b"):
                break
            base = re.sub(r"(eq|ne|ge|lt|gt|le|hi|ls|cs|cc)$", "", mnem)
            srcs = regs if (NO_WRITE.match(base) or base.startswith(("stm", "push"))) else regs[1:]
            if "r0" in srcs:
                return True
            if regs[:1] == ["r0"] and not NO_WRITE.match(base):
                break
    return False


def infer() -> dict[str, str]:
    funcs = functions()
    sites = call_sites(funcs)
    protos = {}
    for name, body in funcs.items():
        n = count_args(body)
        params = ", ".join(["M2C_UNK"] * n) if n else "void"
        ret = "M2C_UNK" if returns_value(sites.get(name, [])) else "void"
        protos[name] = f"{ret} {name}({params});"
    return protos


if __name__ == "__main__":
    p = infer()
    for k in ["func_02084450", "VEC_DotProduct", "func_02001588", "func_02014910"]:
        print(p.get(k))
    print(len(p), "functions")
