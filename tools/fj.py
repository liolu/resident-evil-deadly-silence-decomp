"""fj.py DIR [-j N] [--ov|--main] [--min A --max B] [--fresh] [names...]  -- FAST judge (replaces batch_try + fixrun).
Run from a project dir. In-process workers (workbench imported ONCE per worker, no `info`, no 5 subprocesses per
function): ~4-8x faster than batch_try/fixrun.
 * name has DIR/NAME.c  -> judge that file (re-judged only if newer than its result, like fixrun)
 * otherwise            -> write the m2c draft to DIR/NAME.c first (like batch_try) and judge it
 * no names              -> every unmatched function of report.json.gz in the size range (like batch_try)
Writes DIR/results.json {name:{status,match,profile,k,size,mt}} (batch_try/fixrun/submit-many compatible).
Speed-ups: profiles are tried in the order of the last winning profile; a function that fails to COMPILE on 2
profiles is not tried on the rest; Env AUTO_EXTRA_PROFILES is honoured (workbench reads it)."""
import argparse, gzip, hashlib, importlib, json, os, sys, time
from multiprocessing import Pool

ap = argparse.ArgumentParser()
ap.add_argument('out'); ap.add_argument('-j', type=int, default=12)
ap.add_argument('--ov', action='store_true'); ap.add_argument('--main', action='store_true')
ap.add_argument('--min', type=int, default=4); ap.add_argument('--max', type=int, default=1500)
ap.add_argument('--fresh', action='store_true', help='ignore results.json / cache')
ap.add_argument('--submit', action='store_true'); ap.add_argument('names', nargs='*')
a = ap.parse_args()
OUT = os.path.abspath(a.out); os.makedirs(OUT, exist_ok=True)
sys.path.insert(0, os.path.abspath('tools'))
RANK = {'match': 0, 'near': 1, 'size': 2, 'compile': 3}
wbm = None; cur = None


def init():
    global wbm
    import workbench; wbm = workbench


def judge_one(name):
    global cur
    ov = wbm.overlay_index().get(name)
    mod = 'main' if ov is None else ('itcm' if ov < 0 else f'ov{ov:03d}')
    if mod != cur:  # select_module drops the symbol/reloc caches: only call it when the module changes
        if mod == 'main':
            if cur is not None: importlib.reload(wbm)
        else:
            wbm.select_module(name)
        cur = mod
    f = wbm.function(name)
    if wbm.covered(f['addr']): return name, None
    p = os.path.join(OUT, name + '.c')
    if not os.path.exists(p):
        d, _ = wbm.starting_draft(name)
        open(p, 'w', encoding='utf-8', newline='\n').write(d or '')
    src = open(p, encoding='utf-8', errors='replace').read()
    profs = ([f"{v} {e} -thumb".replace('  ', ' ') for v, e in wbm.am.COMPILERS] if f['mode'] == 'thumb'
             else [f'{v} {e}'.strip() for v, e in wbm.am.profiles_for(name, f['size'], f['addr'])])
    best, ncomp, t0 = None, 0, time.time()
    for prof in profs:
        r = wbm.judge(name, src, prof)
        if r['status'] == 'refused': best = r; break
        if r['status'] == 'compile':
            ncomp += 1
            if 'timeout' in r.get('errors', ''): ncomp = 9  # the compiler loops on this source: do not wait 15 s per profile
            if best is None: best = dict(r, profile=prof)
            if ncomp >= 2: break
            continue
        if best is None or best['status'] == 'compile' or RANK[r['status']] * 10**6 + r.get('diffs', 0) < \
                RANK[best['status']] * 10**6 + best.get('diffs', 0):
            best = dict(r, profile=prof)
        if best['match']: break
    st = best['status']
    k = [0 if best.get('match') else 1, best.get('diffs', 999) if st != 'compile' else 9999]
    return name, {'size': f['size'], 'status': st, 'match': bool(best.get('match')), 'profile': best.get('profile'),
                  'k': k, 'mt': os.path.getmtime(p), 't': round(time.time() - t0, 1)}


def safe(n):
    try: return judge_one(n)
    except Exception as e: return n, {'status': 'error', 'match': False, 'k': [1, 9999], 'err': str(e)[:200], 'mt': 0}


if __name__ == '__main__':
    resf = os.path.join(OUT, 'results.json')
    res = {} if a.fresh or not os.path.exists(resf) else json.load(open(resf))
    names = a.names
    if not names:
        names = [f[:-2] for f in os.listdir(OUT) if f.endswith('.c') and '.v' not in f]
        if not names or a.ov or a.main:
            d = json.load(gzip.open('progress/report.json.gz'))
            have = {f[:-2] for f in os.listdir('src/auto')}
            c = set()
            for u in d['units']:
                isov = '@ov' in u['name'] or u['name'].startswith('ov')
                if (a.ov and not isov) or (a.main and isov): continue
                for f in u.get('functions', []):
                    if f.get('fuzzy_match_percent', 0) < 100 and f['name'] not in have and a.min <= int(f['size']) <= a.max:
                        c.add((int(f['size']), f['name']))
            names = sorted(set(names) | {n for _, n in c})
    todo = []
    for n in names:
        p = os.path.join(OUT, n + '.c')
        if n in res and res[n].get('mt', 0) >= (os.path.getmtime(p) if os.path.exists(p) else 0): continue
        todo.append(n)
    todo.sort()
    print(len(names), 'names,', len(todo), 'to judge', flush=True)
    t0 = time.time(); done = 0
    with Pool(a.j, initializer=init) as pool:
        for n, r in pool.imap_unordered(safe, todo, chunksize=4):
            if r is None: continue
            res[n] = r; done += 1
            if r['match'] or done % 100 == 0:
                print(n, r['status'], r['k'], f'[{done}/{len(todo)} {time.time()-t0:.0f}s]', flush=True)
                json.dump(res, open(resf, 'w'), indent=1)
    json.dump(res, open(resf, 'w'), indent=1)
    import collections
    print('slowest:', sorted(((v.get('t', 0), n) for n, v in res.items()), reverse=True)[:5])
    print(collections.Counter(v['status'] for v in res.values()), 'matches:', sum(1 for v in res.values() if v['match']))
