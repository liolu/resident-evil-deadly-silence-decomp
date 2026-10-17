"""structcopy.py SRC OUT : runs (>=3) of `M2C_FIELD(A, uN *, d) = [(uN)] M2C_FIELD(B, uN *, s);` with contiguous offsets -> one struct assignment
`*(S *)((u8 *)A + d0) = *(S *)((u8 *)B + s0);` (mwcc emits ldrh/strh pairs in the target order). Then fixrun.py OUT; submit-many."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
L = re.compile(r'^(\s*)M2C_FIELD\((\w+), (\w+) \*, (0x[0-9A-Fa-f]+|\d+)\) = (?:\(\w+\) )?M2C_FIELD\((\w+), \3 \*, (0x[0-9A-Fa-f]+|\d+)\);$')
SZ = {'s8': 1, 'u8': 1, 's16': 2, 'u16': 2, 's32': 4, 'u32': 4}
n = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    lines = open(os.path.join(src, f)).read().split('\n'); o = []; i = 0; cnt = 0; ch = False; defs = []
    while i < len(lines):
        m = L.match(lines[i]); run = []
        while m and (not run or (m.group(2) == run[0].group(2) and m.group(5) == run[0].group(5) and m.group(3) == run[0].group(3)
                     and int(m.group(4), 0) == int(run[-1].group(4), 0) + SZ.get(m.group(3), 0)
                     and int(m.group(6), 0) == int(run[-1].group(6), 0) + SZ.get(m.group(3), 0))):
            if m.group(3) not in SZ: break
            run.append(m); i += 1; m = L.match(lines[i]) if i < len(lines) else None
        if len(run) >= 3:
            t = run[0].group(3); cnt += 1; nm = f'SC{cnt}'
            defs.append(f'typedef struct {{ {t} ' + ', '.join(f'f{k}' for k in range(len(run))) + f'; }} {nm};')
            d0, s0 = int(run[0].group(4), 0), int(run[0].group(6), 0)
            o.append(f'{run[0].group(1)}*({nm} *)((u8 *){run[0].group(2)} + {d0}) = *({nm} *)((u8 *){run[0].group(5)} + {s0});'); ch = True
        elif run:
            o.extend(lines[i - len(run):i])
        else:
            o.append(lines[i]); i += 1
    if ch:
        t = '\n'.join(o); k = t.index('\n', t.index('#include'))
        t = t[:k + 1] + '\n'.join(defs) + '\n' + t[k + 1:]
        open(os.path.join(out, f), 'w').write(t); n += 1
print('wrote', n)
