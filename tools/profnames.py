"""profnames.py OUT.json : overlays are built with mwccarm -profile: each function has a `.data` record = its own name string (referenced by a
pool word passed to __PROFILE_ENTRY func_0200fb24). Maps func_ovNNN_ADDR -> {name, rec:[start,end]} from relocs + ROM bytes (run in project dir)."""
import re, sys, json, os, collections
from pathlib import Path
ov_dir = Path('config/eu/arm9/overlays'); res = {}
for d in sorted(ov_dir.glob('ov*')):
    sym = (d / 'symbols.txt').read_text(errors='replace'); head = (d / 'delinks.txt').read_text().split('\n\n', 1)[0]
    base = int(re.search(r'start:0x([0-9a-f]+)', head).group(1), 16)
    data = re.search(r'\.data\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)', head)
    if not data: continue
    ds, de = int(data.group(1), 16), int(data.group(2), 16)
    rom = open(f'extract/eu/arm9_overlays/{d.name}.bin', 'rb').read()
    funcs = []
    for m in re.finditer(r'^(\S+) kind:function\(arm,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)', sym, re.M):
        funcs.append((int(m.group(3), 16), int(m.group(2), 16), m.group(1)))
    funcs.sort()
    import bisect
    starts = [f[0] for f in funcs]
    loads = collections.defaultdict(list)
    for m in re.finditer(r'^from:0x([0-9a-f]+) kind:load to:0x([0-9a-f]+)', (d / 'relocs.txt').read_text(), re.M):
        fa, to = int(m.group(1), 16), int(m.group(2), 16)
        i = bisect.bisect_right(starts, fa) - 1
        if i >= 0 and fa < funcs[i][0] + funcs[i][1] and ds <= to < de: loads[funcs[i][2]].append(to)
    for a, s, nm in funcs:
        for to in loads.get(nm, [])[:1]:   # the first data pool load is the profile record
            o = to - base
            m = re.match(rb'([A-Za-z_][\w:~<>,\*&]*)\x00', rom[o:o + 128])
            if not m: continue
            n = m.group(1).decode(); end = to + ((len(n) + 1 + 3) // 4 * 4)
            res[nm] = {'name': n, 'rec': [to, end], 'ov': d.name}
cnt = collections.Counter(v['name'] for v in res.values())
for v in res.values(): v['dup'] = cnt[v['name']] > 1
json.dump(res, open(sys.argv[1], 'w'), indent=0)
print(len(res), 'functions,', sum(1 for v in res.values() if v['dup']), 'with a duplicate name')
