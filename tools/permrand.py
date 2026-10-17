"""permrand.py NAME FILE.c [--n 300] [-j 6] [--profile P] [--submit]
Random permutations of the local declaration lines (one declaration per line, no initializer; 'a, b;' lists are split
first) of NAME, judged in parallel. Writes FILE.best.c when better than FILE.c. Use when permdecl.py (first 800 in
lexicographic order only) is too narrow, i.e. 7+ locals. Run from the project dir."""
import json, random, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
a = sys.argv[1:]
def opt(k, d):
    return a[a.index(k) + 1] if k in a else d
n_try, jobs, sub = int(opt('--n', 300)), int(opt('-j', 6)), '--submit' in a
name, f = a[0], a[1]
def wb(*x):
    r = subprocess.run(['python', 'tools/workbench.py', *x], capture_output=True, text=True)
    try: return json.loads(r.stdout)
    except Exception: return {}
prof = opt('--profile', None) or wb('info', name).get('profiles', ['2.0/sp1p5'])[0]
L = open(f).read().split('\n')
i0 = next(i for i, l in enumerate(L) if re.match(r'^\w[^;]*\b' + re.escape(name) + r'\(', l))
while not L[i0].rstrip().endswith('{'):  # the signature may span several lines
    i0 += 1
i0 += 1
j = i0
decl = []
while j < len(L) and re.match(r'^\s+[A-Za-z_][\w \*]*(,[\w \*]+)*;\s*$', L[j]) and '=' not in L[j]:
    m = re.match(r'^(\s+)([A-Za-z_][\w ]*?)\s*(\*?)\s*(\w.*);\s*$', L[j])
    ty = re.match(r'^\s+((?:\w+ )*\w+)\s*(.*);', L[j])
    base = ty.group(1); rest = ty.group(2)
    # split 'unsigned int *a, b' -> pointer stars stay with each name
    for part in rest.split(','): decl.append(f"    {base} {part.strip()};")
    j += 1
if not decl:
    # first token handling for e.g. 'int i, j;' where group(1) swallowed the first name
    pass
print(len(decl), 'decl lines')
def judge(order, tag):
    txt = '\n'.join(L[:i0] + [decl[k] for k in order] + L[j:])
    p = f"{f}.{tag}.tmp.c"; open(p, 'w').write(txt)
    r = wb('judge', name, p, '--profile', prof)
    d = 0 if r.get('match') else (r.get('diffs', 10**8) + 1000 * abs(r.get('size', 0) - r.get('target_size', 0))
                                  if r.get('status') in ('near', 'size') else 10**9)
    return d, txt
base_d, base_txt = judge(list(range(len(decl))), 'b')
print('base', base_d)
best = (base_d, None)
orders = []
random.seed(1)
for _ in range(n_try):
    o = list(range(len(decl))); random.shuffle(o); orders.append(o)
with ThreadPoolExecutor(jobs) as ex:
    for k, (d, txt) in enumerate(ex.map(lambda t: judge(t[1], t[0]), enumerate(orders))):
        if d < best[0]: best = (d, txt); print('perm', k, d, flush=True)
        if d == 0: break
if best[1]:
    open(f[:-2] + '.best.c', 'w').write(best[1])
    print('written', f[:-2] + '.best.c', best[0])
