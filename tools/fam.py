"""fam.py SRC_DIR OUT_DIR : regex family rewrites of small near drafts (hand-found patterns). Then: fj.py OUT_DIR names... ; workbench.py submit-many OUT_DIR.
Families: paircopy (2 words copied *(a)=*(b+K) , *(a+4)=*(b+K+4) -> struct assign), postinc getter (T v=*p; obj->p=p+n; return v -> *p++)."""
import sys, os, re
src, out = sys.argv[1:3]; os.makedirs(out, exist_ok=True)
F = r'M2C_FIELD\(%s, (\w+) \*, (0x[0-9A-Fa-f]+|\d+)\)'
n = 0
for fn in os.listdir(src):
    if not fn.endswith('.c'): continue
    t = open(os.path.join(src, fn)).read(); name = fn[:-2]; new = None
    # pair copy
    m = re.search(r'void %s\(void \*arg0, void \*arg1\) \{\s*M2C_FIELD\(arg0, s32 \*, 0\) = \(s32\) M2C_FIELD\(arg1, s32 \*, (0x[0-9A-F]+|\d+)\);\s*M2C_FIELD\(arg0, s32 \*, 4\) = \(s32\) M2C_FIELD\(arg1, s32 \*, (0x[0-9A-F]+|\d+)\);\s*\}' % name, t)
    if m and int(m.group(2), 0) == int(m.group(1), 0) + 4:
        new = 'typedef struct {s32 a, b;} P;\nvoid %s(P *a, P *b) {\n    *a = *(P *)((u8 *)b + %s);\n}\n' % (name, m.group(1))
    # post-increment getter
    m = re.search(r'(\w+) %s\(void \*arg0\) \{\s*(\w+) \*temp_r1;\s*temp_r1 = M2C_FIELD\(arg0, \w+ \*\*, (0x[0-9A-F]+|\d+)\);\s*M2C_FIELD\(arg0, \w+ \*\*, \3\) = \(\w+ \*\) \(temp_r1 \+ (\d+)\);\s*return \*temp_r1;\s*\}' % name, t)
    if m:
        ty = m.group(2); sz = {'s16': 2, 'u16': 2, 's32': 4, 'u32': 4, 's8': 1, 'u8': 1}.get(ty)
        step = int(m.group(4))
        if sz and step * sz // 1 == step * sz and True:
            # draft scaled increment: temp_r1 + step elements of type ty; hm draft is m2c-confused, try element step 1
            new = '%s %s(void *arg0) {\n    %s *p = *(%s **)((u8 *)arg0 + %s);\n    %s v = *p++;\n    *(%s **)((u8 *)arg0 + %s) = p;\n    return v;\n}\n' % (m.group(1), name, ty, ty, m.group(3), ty, ty, m.group(3))
    if new:
        open(os.path.join(out, fn), 'w').write('#include "m2c.h"\n\n' + new); n += 1
print(n, 'rewritten')
