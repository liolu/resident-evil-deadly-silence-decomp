"""profrename.py PROFNAMES.json [old1 old2 ...]: renames func_ovNNN_ADDR -> real name (the -profile record string) in the overlay
symbols.txt and include/m2c_protos.h (skips duplicate names), and writes build/profnames.json keyed by the NEW names
(read by workbench: gives the `.data` record range of the delinks entry). Run from the project dir. No other file refers to those names."""
import sys, json, re, os
from pathlib import Path
m = json.load(open(sys.argv[1])); only = set(sys.argv[2:])
rn = {o: v for o, v in m.items() if not os.path.exists(f'src/auto/{o}.c') and not v['dup'] and (not only or o in only) and re.fullmatch(r'[A-Za-z_]\w*', v['name'])}
taken = set()
for sf in [Path('config/eu/arm9/symbols.txt'), Path('config/eu/arm9/itcm/symbols.txt'), *Path('config/eu/arm9/overlays').glob('ov*/symbols.txt')]:
    if sf.exists():
        for mm in re.finditer(r'^(\S+) kind:', sf.read_text(encoding='utf-8', errors='replace'), re.M): taken.add(mm.group(1))
for o in list(rn):   # a name already used by another symbol (e.g. VBlankIntr in os_china.o) would be multiply defined
    if rn[o]['name'] in taken: del rn[o]

for o, v in list(rn.items()):
    if v['name'] in taken: del rn[o]
    taken.add(v['name'])
by_ov = {}
for o, v in rn.items(): by_ov.setdefault(v['ov'], {})[o] = v['name']
for ov, mp in by_ov.items():
    p = Path(f'config/eu/arm9/overlays/{ov}/symbols.txt'); t = p.read_text(encoding='utf-8')
    t = re.sub(r'^(\S+)( kind:)', lambda x: (mp.get(x.group(1), x.group(1)) + x.group(2)), t, flags=re.M)
    # the record's data symbol becomes a label: the TU's compiler-made `@N` symbol replaces it (dsd checks data symbols by name)
    for o2, v2 in rn.items():
        if v2['ov'] == ov:
            t = t.replace('data_%s_%08x kind:data(any) addr:0x%08x' % (ov, v2['rec'][0], v2['rec'][0]), 'data_%s_%08x kind:label(arm) addr:0x%08x' % (ov, v2['rec'][0], v2['rec'][0]))
    p.write_text(t, encoding='utf-8', newline='\n')
allm = {o: v['name'] for o, v in rn.items()}
srcs = [Path('include/m2c_protos.h')] + [q for q in Path('src').rglob('*.c')]
for p in srcs:
    t = p.read_text(encoding='utf-8')
    t = re.sub(r'\b(func_ov\d+_[0-9a-f]{8})\b', lambda x: allm.get(x.group(1), x.group(1)), t)
    p.write_text(t, encoding='utf-8', newline='\n')
cur = {}
f = Path('build/profnames.json')
if f.exists(): cur = json.load(open(f))
for o, v in rn.items(): cur[v['name']] = {'rec': v['rec'], 'old': o}
json.dump(cur, open(f, 'w'))
print('renamed', len(rn))
