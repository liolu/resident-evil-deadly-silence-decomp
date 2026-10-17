"""modfix.py SRC_DIR OUT_DIR : m2c expands signed `y % K` as `x - K * ((x >> 0x1F) + (y / K))` (x = copy of y). Rewrites to `y % K`
(and makes the vars s32) in every draft that has the shape. Then: fixrun.py OUT_DIR ; submit-many."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
pat = re.compile(r"(?:\((?:s32|u32)\) )?\(?\b(\w+) - \((0x[0-9A-F]+|\d+) \* \(\(\1 >> 0x1F\) \+ \((\w+) / (\d+)\)\)\)\)?")
k = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    t = open(os.path.join(src, f)).read()
    ms = list(pat.finditer(t))
    if not ms: continue
    for m in ms:
        if int(m.group(2), 0) != int(m.group(4)): break
    else:
        for m in reversed(ms):
            t = t[:m.start()] + f"({m.group(3)} % {m.group(4)})" + t[m.end():]
        for m in ms:
            for v in (m.group(1), m.group(3)):
                t = re.sub(r"\bu32 " + v + r"\b", "s32 " + v, t)
        open(os.path.join(out, f), 'w').write(t); k += 1
print('wrote', k)
