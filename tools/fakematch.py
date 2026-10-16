"""Fake matches: code that gets the target's bytes without being C that compiles to them.

    from fakematch import fake_match
    why = fake_match(candidate, starting_file)   # None when the candidate is plain C

Inline assembly, preprocessor tricks, sections, machine code written as numbers, or preprocessor lines the starting
file did not have. Everything is counted against the starting file, so what it already had (an asm function written
by auto_match for instructions no compiler emits, the file's own #include lines) stays allowed. Comments and strings
are ignored.
"""
import re

_STRIP = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)
FAKE = [
    (re.compile(r"\b(?:__)?asm(?:__)?\b"), "inline assembly (asm)"),
    (re.compile(r"##|\b_Pragma\b"), "preprocessor tricks (## or _Pragma)"),
    (re.compile(r"\b__declspec\b|\b__attribute__\b"), "__declspec/__attribute__ (sections, naked functions)"),
    (re.compile(r"\.(?:incbin|section|word|byte|long)\b"), "assembler directives"),
]
OPCODE = re.compile(r"\b0x[eE][0-9a-fA-F]{7}\b")  # an ARM instruction (condition AL) written as a number


def _directives(code: str) -> list[str]:
    return [re.sub(r"\s+", " ", l.strip()) for l in code.split("\n") if l.lstrip().startswith("#")]


def fake_match(code: str, base: str | None) -> str | None:
    """Why `code` would be a fake match, or None when it is plain C (compared with the starting file `base`)."""
    c, b = _STRIP.sub(" ", code), _STRIP.sub(" ", base or "")
    for pattern, why in FAKE:
        if len(pattern.findall(c)) > len(pattern.findall(b)):
            return why
    if len(OPCODE.findall(c)) - len(OPCODE.findall(b)) >= 3:
        return "machine code written as numbers"
    known = list(_directives(b))
    for d in _directives(c):
        if d in known:
            known.remove(d)
        else:
            return f"new preprocessor line `{d[:60]}`"
    return None
