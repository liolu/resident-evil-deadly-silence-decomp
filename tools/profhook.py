"""profhook.py SRC OUT : Heroes of Mana overlays are compiled with mwccarm `-profile`: every function is bracketed by
func_0200fb24(&data_ovXXX_...) (enter, `push {r0,lr}`) and func_0200fb28() (exit). m2c shows those as calls (and the saved r0 as
SECOND_REG junk). Strip the hooks from the draft: the compiler re-emits them with `-profile` (profile string "1.2/sp3 -profile").
 - `func_0200fb24(&data);` statement removed; `T = func_0200fb24(&data)` => T replaced by arg0 / SECOND_REG(T) by arg1 (params added)
 - `func_0200fb28(X);` => `return X;` (ret type void -> s32) ; `func_0200fb28();` => removed (or `return;` kept)
Then: AUTO_EXTRA_PROFILES='1.2/sp3 -profile,2.0/sp1p5 -profile' fixrun.py OUT ; submit-many OUT"""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
names = sys.argv[3:] or [f[:-2] for f in os.listdir(src) if f.endswith('.c')]
n = 0
for nm in names:
    p = os.path.join(src, nm + '.c')
    if not os.path.exists(p): continue
    t = open(p).read()
    if 'func_0200fb24' not in t: continue
    t = re.sub(r'^[^\n(]*\bfunc_0200fb(24|28)\([^\n]*\);\s*/\* extern \*/\n', '', t, flags=re.M) if False else t
    t = re.sub(r'^[^\n=(]*func_0200fb(?:24|28)\([^()]*\);[ ]*/\* extern \*/\n', '', t, flags=re.M)
    t = re.sub(r'^extern [^\n]*func_0200fb(?:24|28)[^\n]*\n', '', t, flags=re.M)
    t = re.sub(r'^\s*func_0200fb28\(func_0200fb24\(&\w+\)\);\s*$', '', t, flags=re.M)
    lines = t.split('\n'); o = []; ret_needed = False; var = None
    for l in lines:
        m = re.match(r'^(\s*)(?:(\w+) = )?func_0200fb24\(&\w+\);\s*$', l)
        if m:
            if m.group(2): var = m.group(2)
            continue
        m = re.match(r'^(\s*)func_0200fb28\((.*)\);\s*$', l)
        if m:
            if m.group(2).strip(): o.append(f'{m.group(1)}return {m.group(2)};'); ret_needed = True
            continue
        o.append(l)
    t = '\n'.join(o)
    if var:
        t = re.sub(r'SECOND_REG\(' + var + r'\)', 'arg1', t); t = re.sub(r'\b' + var + r'\b', 'arg0', t)
        t = re.sub(r'^\s*(s32|u32|void \*|M2C_UNK) arg0;\n', '', t, flags=re.M)
        t = re.sub(r'^\s*(s32|u32|void \*|M2C_UNK) temp_r\d+ = arg\d;\n', '', t, flags=re.M)
        m = re.search(r'^(\w[\w \*]*?)\b' + nm + r'\(([^)]*)\) \{', t, re.M)
        if m:
            ps = m.group(2).strip(); need = 2 if 'arg1' in t else 1
            have = [] if ps in ('', 'void') else [x.strip() for x in ps.split(',')]
            base = [x for x in have if not re.search(r'arg[01]$', x)]
            if len(have) < 1 or not any(re.search(r'arg0$', x) for x in have):
                t = t[:m.start(2)] + ', '.join(['void *arg0'] + (['void *arg1'] if need == 2 else []) + base) + t[m.end(2):]
    if ret_needed:
        t = re.sub(r'^void ' + nm + r'\(', 's32 ' + nm + '(', t, flags=re.M)
    # a trailing `return;` right before the closing brace is pointless
    open(os.path.join(out, nm + '.c'), 'w').write(t); n += 1
print('wrote', n)
