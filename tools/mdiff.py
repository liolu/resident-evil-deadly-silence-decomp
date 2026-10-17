"""mdiff.py NAME FILE.c [profile] [--ctx N]: structural diff of a judge result. Aligns the FULL target/candidate listings
with difflib on the mnemonic only (registers/immediates ignored; branch targets ignored) and prints what was inserted /
deleted / replaced, with the real instructions. Much more useful than the index-aligned `diff` of size mismatches.
Run from the project dir."""
import difflib, json, os, subprocess, sys
a = [x for x in sys.argv[1:]]
name, f = a[0], a[1]
prof = a[2] if len(a) > 2 and not a[2].startswith('--') else '2.0/sp1p5'
env = dict(os.environ, WB_FULL='1')
r = subprocess.run(['python', 'tools/workbench.py', 'judge', name, f, '--profile', prof], capture_output=True, text=True, env=env)
d = json.loads(r.stdout)
if not d.get('full'):
    print(d.get('status'), (d.get('errors') or '')[:800]); sys.exit()
T, C = d['full']['t'], d['full']['c']
key = lambda s: s.split()[0] if s.split() else ''
sm = difflib.SequenceMatcher(None, [key(x) for x in T], [key(x) for x in C], autojunk=False)
print(f"{d['status']} diffs={d['diffs']} size {d['size']}/{d['target_size']}  (target {len(T)} insns, cand {len(C)})")
for op, a0, a1, b0, b1 in sm.get_opcodes():
    if op == 'equal': continue
    print(f'--- {op} t[{a0}:{a1}] c[{b0}:{b1}]')
    for x in T[a0:a1]: print('  T', x)
    for x in C[b0:b1]: print('  C', x)
