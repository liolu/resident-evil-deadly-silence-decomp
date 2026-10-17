"""vcall.py SRC OUT NAMES... : m2c vcall idioms that drop `this`:
 T1 M2C_FIELD(M2C_FIELD(P, void **, A), R (**)(), K)()   -> this=(u8*)P+A, vtable=*this
 T2 M2C_FIELD(*M2C_FIELD(P, void ***, A), R (**)(), K)() -> this=*(void**)((u8*)P+A), vtable=*this
 (P is a simple identifier). Writes OUT/NAME.c for changed drafts; then fixrun.py OUT --submit."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
names = sys.argv[3:] or [f[:-2] for f in os.listdir(src) if f.endswith('.c')]
T1 = re.compile(r'M2C_FIELD\(M2C_FIELD\((\w+), void \*\*, (\w+)\), (\w[\w ]*?) \(\*\*\)\(\), (\w+)\)\(\)')
T2 = re.compile(r'M2C_FIELD\(\*M2C_FIELD\((\w+), void \*\*\*, (\w+)\), (\w[\w ]*?) \(\*\*\)\(\), (\w+)\)\(\)')
T3 = re.compile(r'M2C_FIELD\(\*(\w+), (\w[\w ]*?) \(\*\*\)\(\), (\w+)\)\(\)')
def r3(m):
    p, r, k = m.groups()
    return f'(*({r} (**)(void *))(*(u8 **){p} + {k}))({p})'
def r1(m):
    p, a, r, k = m.groups(); o = f'((u8 *){p} + {a})'
    return f'(*({r} (**)(void *))(*(u8 **){o} + {k}))({o})'
def r2(m):
    p, a, r, k = m.groups(); o = f'(*(void **)((u8 *){p} + {a}))'
    return f'(*({r} (**)(void *))(*(u8 **){o} + {k}))({o})'
def fixargs(t, n):
    m = re.search(r'^(\w[\w \*]*?)' + n + r'\(([^)]*)\) \{', t, re.M)
    if m and m.group(2).strip() not in ('', 'void'):
        params = [x.strip() for x in m.group(2).split(',')]
        have = {int(re.search(r'arg(\d+)', x).group(1)): x for x in params if re.search(r'arg(\d+)', x)}
        if have and (min(have) > 0 or set(range(max(have) + 1)) - set(have)):
            allp = [have.get(i, f'void *arg{i}') for i in range(max(have) + 1)]
            t = t[:m.start(2)] + ', '.join(allp) + t[m.end(2):]
    return t
n = 0
for nm in names:
    p = os.path.join(src, nm + '.c')
    if not os.path.exists(p): continue
    t = open(p).read(); o = t
    t = T1.sub(r1, t); t = T2.sub(r2, t); t = T3.sub(r3, t)
    t = fixargs(t, nm)
    if t != o: open(os.path.join(out, nm + '.c'), 'w').write(t); n += 1
print('wrote', n)
