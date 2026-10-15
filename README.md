# Resident Evil: Deadly Silence decompilation (USA)

Nintendo DS, game code `ABHE`. Matching decompilation with Metrowerks mwccarm (compiler version still to be identified: `python tools/probe_compiler.py`).

No game assets in this repository: see `extract/README.md`.

## Progress

<!-- progress:start -->
`██░░░░░░░░░░░░░░░░░░` **10.88%** of the code matched · data 0.00% · 2064/5825 functions

| Part of the code | Files | Functions | Share of all code |
|---|---|---|---|
| Auto-matched (raw m2c output, to clean up) | 2014 | 2014/2014 | 10.37% |
| Reused from other decompilations, not merged into files yet | 50 | 50/50 | 0.51% |

*Updated 2026-10-15 by `python tools/match.py progress` ([DS Decomp Studio](https://github.com/liolu/ds-decomp-studio)). A function counts only when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*
<!-- progress:end -->

```shell
python tools/configure.py usa
ninja
python tools/match.py status
```

Created from the rayman-rr template. See `AGENTS.md` for the rules.
