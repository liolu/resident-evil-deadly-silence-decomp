"""tryc.py NAME 'C body 1' 'C body 2' ... [-p PROFILE] : judge several inline C variants of a function (m2c.h auto-included); prints diff count per variant + the diff of the best. Run from project dir. Use '@file.c' to load a variant from a file."""
import sys, os, subprocess, tempfile, re
a = sys.argv[1:]; name = a.pop(0); prof = []
if '-p' in a: i = a.index('-p'); prof = ['--profile', a[i+1]]; del a[i:i+2]
best = None
for k, src in enumerate(a):
    if src.startswith('@'): src = open(src[1:]).read()
    if '#include' not in src: src = '#include "m2c.h"\n' + src
    p = os.path.join(tempfile.gettempdir(), f'tryc_{name}_{k}.c'); open(p, 'w').write(src)
    out = subprocess.run([sys.executable, '../../tools/j.py', name, p] + prof, capture_output=True, text=True).stdout
    m = re.match(r'(\w+) profile (\S+(?: \S+)?) diffs (\S+) size (\S+) / (\S+)', out)
    print(k, out.split('\n')[0][:90])
    d = 9999 if not m or m.group(3) == 'None' else int(m.group(3))
    if m and m.group(1) == 'match': print('MATCH variant', k, 'file', p); sys.exit(0)
    if best is None or d < best[0]: best = (d, out)
if best: print(best[1][:1500])
