"""bittail.py SRC_DIR OUT_DIR : rewrites the tail `temp_r2 = bit(word@SYM+OFF); if (!temp_r2) return; word &= ~mask; call(&SYM, word, temp_r2)`
(m2c, many per-overlay scene exits) with a bitfield struct: `temp_r2 = SYM.f.b; ...; SYM.f.b = 0; call((s32*)(void*)&SYM, *(s32*)(void*)&SYM.f, temp_r2)`.
Then: fixrun.py OUT_DIR ; workbench submit-many OUT_DIR."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
pat = re.compile(r"    temp_r2 = \(u32\) \(M2C_FIELD\(&(\w+), s32 \*, (0x[0-9A-F]+)\) << (\d+|0x[0-9A-F]+)\) >> 0x1F;\n    if \(temp_r2 == 0\) \{\n        return;\n    \}\n"
                 r"    temp_r1 = M2C_FIELD\(&\1, s32 \*, \2\) & ~(0x[0-9A-F]+);\n    M2C_FIELD\(&\1, s32 \*, \2\) = temp_r1;\n    (\w+)\(&\1, temp_r1, temp_r2\);\n\}\n")
k = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    t = open(os.path.join(src, f)).read(); m = pat.search(t)
    if not m: continue
    sym, off, sh, mask, fn = m.group(1), int(m.group(2), 16), int(m.group(3), 0), int(m.group(4), 16), m.group(5)
    bit = 31 - sh
    if mask != 1 << bit: continue
    fields = (f"u32 a:{bit}; " if bit else "") + f"u32 b:1; u32 r:{31 - bit};"
    body = (f"    temp_r2 = {sym}.f.b;\n    if (temp_r2 == 0) {{\n        return;\n    }}\n    {sym}.f.b = 0;\n"
            f"    {fn}((s32 *)(void *)&{sym}, *(s32 *)(void *)&{sym}.f, temp_r2);\n}}\n")
    t = t[:m.start()] + body + t[m.end():]
    t = t.replace(f"extern M2C_UNK {sym};", f"typedef struct {{ {fields} }} B_{sym};\ntypedef struct {{ u8 pad[{off}]; B_{sym} f; }} D_{sym};\nextern D_{sym} {sym};")
    t = re.sub(r"\n    s32 temp_r1;\n", "\n", t, 1)
    open(os.path.join(out, f), 'w').write(t); k += 1
print('wrote', k)
