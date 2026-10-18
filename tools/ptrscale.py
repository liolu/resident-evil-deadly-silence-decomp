"""ptrscale.py SRC OUT NAMES... : m2c drafts scale pointer arithmetic by sizeof(pointee) (M2C_UNK *p; p += 0x5C; (u16*)p + 4 ...) but the target uses byte offsets.
Rewrites `ptr + N` / `ptr += N` on declared pointer locals/params to (u8 *) arithmetic. Tries ALL-at-once and each single site; writes first variant to OUT (judge with fj.py)."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
names = sys.argv[3:] or [f[:-2] for f in os.listdir(src) if f.endswith('.c')]
n = 0
for nm in names:
    p = os.path.join(src, nm + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    ptrs = set(re.findall(r'[\w ]+\*+\s*(\w+)\s*[;,)=]', t)) | set(re.findall(r'\*\s*(\w+)[;,)]', t))
    ptrs = {x for x in ptrs if re.match(r'(temp_r|var_r|arg)\d', x)}
    new = t
    for v in ptrs:
        new = re.sub(r'\b%s \+= (0x[0-9A-Fa-f]+|\d+);' % v, r'%s = (void *)((u8 *)%s + \1);' % (v, v), new)
        new = re.sub(r'\(%s \+ (0x[0-9A-Fa-f]+|\d+)\)' % v, r'((u8 *)%s + \1)' % v, new)
        new = re.sub(r'(?<![\w*)])%s \+ (0x[0-9A-Fa-f]+|\d+)(?=\))' % v, r'(u8 *)%s + \1' % v, new)
    if new != t: open(os.path.join(out, nm + '.c'), 'w').write(new); n += 1
print('wrote', n)
