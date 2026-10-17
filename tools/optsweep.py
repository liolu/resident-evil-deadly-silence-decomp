"""optsweep.py NAME FILE.c [versions...] [--submit]: judge FILE.c with every optimisation level (-O0..-O4, ,p/,s) for each
compiler version/service pack (default 2.0/sp1p5 and 1.2/sp2p3) and print the diff counts, best first.
Many 'unsolvable' loops (`b cond` entry, mul/mla instead of strength reduction) are just files built with -O2 / -O1.
Run from a project dir.  --submit submits the first exact match with its profile."""
import sys, json, subprocess
from concurrent.futures import ThreadPoolExecutor
a = [x for x in sys.argv[1:] if not x.startswith('--')]; sub = '--submit' in sys.argv
name, f = a[0], a[1]; vers = a[2:] or ['2.0/sp1p5', '1.2/sp2p3']
def wb(*x):
    r = subprocess.run(['python', 'tools/workbench.py', *x], capture_output=True, text=True)
    try: return json.loads(r.stdout)
    except Exception: return {'status': 'error'}
profs = [f'{v} -O{o},{t}' for v in vers for o in (0, 1, 2, 3, 4) for t in ('p', 's')]
def run(p):
    j = wb('judge', name, f, '--profile', p)
    return (0 if j.get('match') else j.get('diffs', 9999) if j.get('status') in ('near', 'size') else 9999, j.get('status'), p)
with ThreadPoolExecutor(6) as ex: res = sorted(ex.map(run, profs))
for d, st, p in res[:8]: print(d, st, p)
if sub and res[0][0] == 0: print(wb('submit', name, f, '--profile', res[0][2], '--who', 'claude'))
