"""hwvol.py SRC_DIR OUT_DIR : makes hardware register accesses volatile (M2C_FIELD((void *)0x04..., T *, o) and *(T *)0x04...), which stops
the compiler merging/dropping repeated read-modify-write on I/O registers (func_ov111_020eaeb8: size 100 -> exact). Then fixrun.py + submit-many."""
import sys, os, re
src, out = sys.argv[1], sys.argv[2]; os.makedirs(out, exist_ok=True)
k = 0
for f in os.listdir(src):
    if not f.endswith('.c'): continue
    t = open(os.path.join(src, f)).read(); o = t
    t = re.sub(r"(M2C_FIELD\(\(void \*\)0x04\w+, )((?:u8|u16|s16|s32|u32|s8)) \*", r"\1volatile \2 *", t)
    t = re.sub(r"\*\(((?:u8|u16|s16|s32|u32|s8)) \*\)(\(?0x04)", r"*(volatile \1 *)\2", t)
    if t != o: open(os.path.join(out, f), 'w').write(t); k += 1
print('wrote', k)
