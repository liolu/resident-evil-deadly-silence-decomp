"""nearsig.py DIR NEAR.json KMIN KMAX : run judge on near drafts (DIR/NAME.c, fallback nf/sw dirs), group by diff signature (mnemonic pairs) -> families to fix in batch"""
import sys, json, os, subprocess, collections, re
from concurrent.futures import ThreadPoolExecutor
dirs = sys.argv[1].split(','); near = json.load(open(sys.argv[2])); lo, hi = int(sys.argv[3]), int(sys.argv[4])
names = [n for k, s, n in near if lo <= k <= hi]
def find(n):
    for d in dirs[::-1]:
        p = os.path.join(d, n + '.c')
        if os.path.exists(p): return p
def run(n):
    out = subprocess.run(['python', '../../tools/j.py', n, find(n)], capture_output=True, text=True).stdout.split('\n')
    sig = []
    for l in out[2:]:
        m = re.match(r'\s*\d+ \* (\S+)[^|]*\|\s*(\S+)', l)
        if m: sig.append(m.group(1) + '>' + m.group(2))
    return n, ' '.join(sig)
with ThreadPoolExecutor(10) as ex: res = list(ex.map(run, names))
g = collections.defaultdict(list)
for n, s in res: g[s].append(n)
for s, ns in sorted(g.items(), key=lambda x: -len(x[1]))[:40]: print(len(ns), s[:150], ns[:3])
json.dump(res, open(sys.argv[2] + '.sig', 'w'))
