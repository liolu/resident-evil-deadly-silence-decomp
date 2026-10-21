"""Facts about THIS game, read from the project itself.

Every tool of tools/ imports this module instead of hard-coding the version or the ROM name, so the same files work
unchanged in every DS project (their single source is the `gametools/` folder of DS Decomp Studio).

    VERSION     the folder of config/ that holds an arm9 config: usa, eu, jp...
    GAME        the ROM base name: <GAME>_<VERSION>.nds (from <GAME>_<VERSION>.sha1)
    MAIN_TEXT   (start, end) of the .text section of the ARM9 main module (from delinks.txt)
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def _version() -> str:
    found = sorted(p.name for p in (ROOT / "config").iterdir() if (p / "arm9" / "symbols.txt").exists()) \
        if (ROOT / "config").exists() else []
    if not found:
        raise SystemExit(f"No config/<version>/arm9/symbols.txt in {ROOT}: run dsd init first.")
    return found[0]


VERSION = _version()
CONFIG = ROOT / "config" / VERSION
BUILD = ROOT / "build" / VERSION
EXTRACT = ROOT / "extract" / VERSION
ARM9 = CONFIG / "arm9"
DELINKS = ARM9 / "delinks.txt"
SYMBOLS = ARM9 / "symbols.txt"
COMPILERS_TXT = CONFIG / "compilers.txt"
ASM_DIR = BUILD / "asm"
REPORT = BUILD / "report.json"


def _game() -> str:
    for p in ROOT.glob(f"*_{VERSION}.sha1"):
        return p.name[:-len(f"_{VERSION}.sha1")]
    return ROOT.name.replace("-", "_")


GAME = _game()
ROM_NAME = f"{GAME}_{VERSION}.nds"


def _main_text() -> tuple[int, int]:
    m = re.search(r"\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)", DELINKS.read_text(encoding="utf-8"))
    return (int(m.group(1), 16), int(m.group(2), 16)) if m else (0x02000000, 0x02000000)


MAIN_TEXT = _main_text()


def configure_value(var: str, default: str = "", root: Path = ROOT) -> str:
    """Value of a string setting of <root>/tools/configure.py (CC_FLAGS, MWCC_VERSION...) without running it.

    The assignment is evaluated alone with GAME_CFG = <root>/game.toml, so both the old hard-coded configure.py and
    the shared one (values from game.toml) give the flags ninja really uses. Works for another project's root too."""
    import ast
    try:
        tree = ast.parse((root / "tools" / "configure.py").read_text(encoding="utf-8"))
    except (OSError, SyntaxError):
        return default
    cfg = {}
    if (root / "game.toml").exists():
        import tomllib
        cfg = tomllib.loads((root / "game.toml").read_text(encoding="utf-8"))
    for node in tree.body:
        if isinstance(node, ast.Assign) and any(isinstance(t, ast.Name) and t.id == var for t in node.targets):
            try:
                value = eval(compile(ast.Expression(node.value), "configure.py", "eval"), {"__builtins__": {}, "GAME_CFG": cfg})
            except Exception:
                return default
            return value if isinstance(value, str) else default
    return default
