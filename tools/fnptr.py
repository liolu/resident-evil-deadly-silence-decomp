"""fnptr.py SRC OUT : drafts `RET NAME(void) { [return] data_x(); }` (call through a global fn pointer) lose the pass-through args
(callee reg: fn ptr in r1/r2/r3 => 1/2/3 args). Writes OUT/kK/NAME.c for K=1..4 (args s32 a0..); then fixrun.py on each OUT/kK."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]
pat = re.compile(r'^extern M2C_UNK \(\*(\w+)\)\(\);\n\n(\w+) (\w+)\(void\) \{\n    (return )?\1\(\);\n\}', re.M)
n = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    t = open(os.path.join(src, f)).read()
    m = pat.search(t)
    if not m: continue
    d, ret, nm, rt = m.groups()
    for k in range(1, 5):
        os.makedirs(f'{out}/k{k}', exist_ok=True)
        ps = ', '.join(f's32 a{i}' for i in range(k)); as_ = ', '.join(f'a{i}' for i in range(k))
        body = f'#include "m2c.h"\n\nextern {ret} (*{d})({ps});\n\n{ret} {nm}({ps}) {{\n    {"return " if rt else ""}{d}({as_});\n}}\n'
        open(f'{out}/k{k}/{nm}.c', 'w').write(body)
    n += 1
print('families', n)
