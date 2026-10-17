"""profmap.py SRC OUT : copy drafts SRC/func_ovN_ADDR.c to OUT/RealName.c with every old function name replaced by its real name
(build/profnames.json written by profrename.py). Run in the project dir."""
import json, re, os, sys
cur = json.load(open('build/profnames.json')); mp = {v['old']: k for k, v in cur.items()}
src, dst = sys.argv[1], sys.argv[2]; os.makedirs(dst, exist_ok=True)
pat = re.compile(r'\b(func_ov\d+_[0-9a-f]{8})\b'); n = 0
for f in os.listdir(src):
    if f[:-2] not in mp: continue
    t = pat.sub(lambda m: mp.get(m.group(1), m.group(1)), open(f'{src}/{f}').read())
    open(f'{dst}/{mp[f[:-2]]}.c', 'w').write(t); n += 1
print('wrote', n)
