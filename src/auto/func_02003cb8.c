/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02003c14(void *, s32 *, M2C_UNK);      /* extern */
M2C_UNK func_020fec68(s32 *, s32 *);                /* extern */

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} V3;

void func_02003cb8(void *arg0, M2C_UNK arg1) {
    V3 v;
    s32 t8;
    s32 t4;
    s32 t0;

    t8  = 0 - (M2C_FIELD(arg0, s32 *, 0x14) - M2C_FIELD(arg0, s32 *, 8));
    t4  = 0 - (M2C_FIELD(arg0, s32 *, 0x10) - M2C_FIELD(arg0, s32 *, 4));
    t0  = 0 - (M2C_FIELD(arg0, s32 *, 0xC) - M2C_FIELD(arg0, s32 *, 0));
    v.a = t0;
    v.b = t4;
    v.c = t8;
    func_020fec68((s32 *) &v, (s32 *) &v);
    func_02003c14(arg0, (s32 *) &v, arg1);
}
