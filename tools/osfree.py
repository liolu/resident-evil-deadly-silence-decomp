"""osfree.py SRC OUT [names]: m2c drops the 3rd arg of OS_FreeToHeap(0, -1, ptr) (ptr = the tested field): `if (X != 0) { OS_FreeToHeap(0, -1);` -> `OS_FreeToHeap(0, -1, X);`
and fixes the prototype. Then fixrun.py OUT."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
names = sys.argv[3:] or [f[:-2] for f in os.listdir(src) if f.endswith('.c')]
pat = re.compile(r'((?:M2C_FIELD\([^()]*(?:\([^()]*\)[^()]*)*\))|[\w\.]+) != (?:NULL|0)\)+ \{\n(\s*)OS_FreeToHeap\(0, -1\);')
n = 0
for nm in names:
    p = os.path.join(src, nm + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    if 'OS_FreeToHeap(0, -1);' not in t: continue
    t2 = pat.sub(lambda m: m.group(0)[:m.start(2) - m.start(0)] + m.group(2) + f'OS_FreeToHeap(0, -1, {m.group(1)});', t)
    t2 = re.sub(r'OS_FreeToHeap\(M2C_UNK, M2C_UNK\)', 'OS_FreeToHeap(M2C_UNK, M2C_UNK, void *)', t2)
    if t2 != t: open(os.path.join(out, nm + '.c'), 'w').write(t2); n += 1
print('wrote', n)
