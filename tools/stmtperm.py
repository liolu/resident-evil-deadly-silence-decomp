"""stmtperm.py NAME FILE.c [--profile P] [-j N] [--submit]: permute the order of the statement lines tagged with a trailing
`/*P*/` (independent statements, <= 7 lines), judge every order, keep the best in FILE.best.c. Run from a project dir."""
import sys, os, re, json, itertools, subprocess, tempfile
from concurrent.futures import ThreadPoolExecutor
a = sys.argv[1:]; name, f = a[0], a[1]
prof = a[a.index('--profile') + 1] if '--profile' in a else None
j = int(a[a.index('-j') + 1]) if '-j' in a else 6
lines = open(f).read().split('\n')
idx = [i for i, l in enumerate(lines) if l.rstrip().endswith('/*P*/')]
if not prof: prof = json.loads(subprocess.run(['python', 'tools/workbench.py', 'info', name], capture_output=True, text=True).stdout)['profiles'][0]
tmp = tempfile.mkdtemp()
def run(perm):
    L = list(lines)
    for k, i in enumerate(idx): L[i] = lines[idx[perm[k]]]
    p = os.path.join(tmp, 'p%s.c' % ''.join(map(str, perm))); open(p, 'w').write('\n'.join(L))
    r = subprocess.run(['python', 'tools/workbench.py', 'judge', name, p, '--profile', prof], capture_output=True, text=True)
    try: d = json.loads(r.stdout)
    except Exception: return (9999, perm, p)
    return ((0 if d.get('match') else d.get('diffs', 9999) if d.get('status') != 'compile' else 9999), perm, p)
perms = list(itertools.permutations(range(len(idx))))
with ThreadPoolExecutor(j) as ex: res = sorted(ex.map(run, perms))
for s, perm, p in res[:3]: print(s, perm)
best = res[0]; open(os.path.splitext(f)[0] + '.best.c', 'w').write(open(best[2]).read()); print('best', best[0], '->', os.path.splitext(f)[0] + '.best.c')
