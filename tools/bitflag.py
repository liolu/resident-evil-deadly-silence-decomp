"""bitflag.py SRC_DIR OUT_DIR : rewrites the recurring "display init" block (POWCNT 0x04000304 / 0x04001018 writes derived from ONE bit of a global
struct word, m2c: `((u32)(M2C_FIELD(&data_X, s32 *, OFF) << S) >> 0x1F)`) with a bitfield struct (typedef B/D) and operand order
`(bit << 15) | (reg & ~0x8000)`. Then: fixrun.py OUT_DIR ; workbench submit-many OUT_DIR."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
pat = re.compile(r"    M2C_FIELD\(\(void \*\)0x04000304, u16 \*, 0\) = \(u16\) \(\(M2C_FIELD\(\(void \*\)0x04000304, u16 \*, 0\) & ~0x8000\) \| \(\(\(u32\) \(M2C_FIELD\(&(\w+), s32 \*, (0x[0-9A-F]+)\) << (0x[0-9A-F]+|\d+)\) >> 0x1F\) << 0xF\)\);\n"
                 r"(?:    M2C_FIELD\(\(void \*\)0x0400(?:0304, s32 \*, -0x2E[C8]|1018, s32 \*, [04])\) = \(s32\) \(0x01FF0000 & .*\n){4}")
k = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    t = open(os.path.join(src, f)).read()
    m = pat.search(t)
    if not m: continue
    sym, off, sh = m.group(1), int(m.group(2), 16), int(m.group(3), 0)
    bit = 31 - sh
    fields = (f"u32 a:{bit}; " if bit else "") + f"u32 b:1; u32 r:{31 - bit};"
    new = (f"    {{\n    }}\n")
    b = f"{sym}.f.b"
    body = (f"    *(u16 *)0x04000304 = (u16)(({b} << 15) | (*(u16 *)0x04000304 & ~0x8000));\n"
            f"    *(u32 *)(0x04000304 - 0x2EC) = 0x01FF0000 & ({b} << 24);\n"
            f"    *(u32 *)(0x04000304 - 0x2E8) = 0x01FF0000 & ({b} << 24);\n"
            f"    *(u32 *)0x04001018 = 0x01FF0000 & ({b} << 24);\n"
            f"    *(u32 *)0x0400101C = 0x01FF0000 & ({b} << 24);\n")
    t = t[:m.start()] + body + t[m.end():]
    t = t.replace(f"extern M2C_UNK {sym};", f"typedef struct {{ {fields} }} B_{sym};\ntypedef struct {{ u8 pad[{off}]; B_{sym} f; }} D_{sym};\nextern D_{sym} {sym};")
    t = t.replace(f"{b}", f"{b}")
    t = t.replace(f"{sym}.f.b", f"{sym}.f.b")
    open(os.path.join(out, f), 'w').write(t); k += 1
print('wrote', k)
