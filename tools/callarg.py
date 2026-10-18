"""callarg.py SRC OUT [names]: m2c drops a pass-through arg of a call (`fn();` while the callee proto has a parameter and the function
has arg0): rewrite `fn();` -> `fn(arg0);` (also protos `fn()`/`fn(void)` untouched). Then fixrun.py OUT; submit-many."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
names = sys.argv[3:] or [f[:-2] for f in os.listdir(src) if f.endswith('.c')]
n = 0
for nm in names:
    p = os.path.join(src, nm + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    if 'arg0' not in t.split('{', 1)[0]: continue
    protos = dict(re.findall(r'^[\w\* ]+?\b(\w+)\(((?:M2C_UNK|void \*|s32|u32)[^)]*)\);\s*/\* extern \*/', t, re.M))
    def rep(m):
        return f'{m.group(1)}{m.group(2)}(arg0);' if m.group(2) in protos else m.group(0)
    t2 = re.sub(r'^(\s+)(\w+)\(\);', lambda m: f'{m.group(1)}{m.group(2)}(arg0);', t, flags=re.M)
    if t2 != t: open(os.path.join(out, nm + '.c'), 'w').write(t2); n += 1
print('wrote', n)
