"""swdefault.py SRC_DIR OUT_DIR [names...] : m2c puts `default:` FIRST in switch; mwcc jump-table layout wants it LAST.
Moves the `default:` block (up to the next `case`) to the end of the switch. Then: fixrun.py OUT_DIR (+ submit-many)."""
import sys, os, re, json
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
res = json.load(open(os.path.join(src, 'results.json')))
names = sys.argv[3:] or [n for n, r in res.items() if r['status'] in ('near', 'size') and not r.get('match')]
k = 0
for n in names:
    p = os.path.join(src, n + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    m = re.search(r'^( *)default:\n(.*?)(?=^ *case [^\n]*:\n)', t, re.S | re.M)
    if not m: continue
    blk = m.group(0); t2 = t.replace(blk, '', 1)
    ind = m.group(1)
    # end of that switch: first line == indentation-4 + '}' after removal point
    pos = t2.find('\n' + ind + '}\n', m.start())
    if pos < 0: continue
    t2 = t2[:pos + 1] + blk + t2[pos + 1:]
    open(os.path.join(out, n + '.c'), 'w').write(t2); k += 1
print('wrote', k)
