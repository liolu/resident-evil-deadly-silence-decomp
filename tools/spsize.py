"""spsize.py SRC_DIR OUT_DIR [names...] : m2c declares address-taken stack buffers as `M2C_UNK spN;` (4 bytes) -> frame too small.
For each near/size draft with such a local, tries `u8 spN[SIZE]` (SIZE in 8..128 step 4, and `&spN` -> `spN`), judges, keeps matches
in OUT_DIR (OUT_DIR/results.json for workbench submit-many). Uses the profile of the draft's result."""
import sys, os, re, json, subprocess
sys.path.insert(0, os.path.dirname(__file__))
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
res = json.load(open(os.path.join(src, 'results.json')))
names = sys.argv[3:] or [n for n, r in res.items() if r['status'] in ('near', 'size') and not r.get('match')]
done = {}
for n in names:
    p = os.path.join(src, n + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    vs = re.findall(r'^    M2C_UNK (sp[0-9A-F]+);', t, re.M)
    vs = [v for v in vs if re.search(r'&' + v + r'\b', t)]
    if not vs: continue
    prof = res[n].get('profile', '2.0/sp1p5')
    best = None
    for v in vs[:1]:
        for size in range(8, 132, 4):
            t2 = re.sub(r'&' + v + r'\b', v, t.replace(f'M2C_UNK {v};', f'u8 {v}[{size}];'))
            fp = os.path.join(out, n + '.c'); open(fp, 'w').write(t2)
            r = subprocess.run(['python', os.path.join(os.path.dirname(__file__), 'j.py'), n, fp, prof], capture_output=True, text=True).stdout
            if r.startswith('match'): best = r.split('\n')[0]; break
    if best: print(n, best); done[n] = {'status': 'near', 'match': True, 'profile': prof, 'k': [0, 0]}
    elif os.path.exists(os.path.join(out, n + '.c')): os.remove(os.path.join(out, n + '.c'))
json.dump(done, open(os.path.join(out, 'results.json'), 'w'))
print('matched', len(done))
