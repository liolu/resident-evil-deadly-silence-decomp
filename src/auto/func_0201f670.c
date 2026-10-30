/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd504(s16);                         /* extern */
M2C_UNK func_0201ea80(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */

void func_0201f670(void *arg0) {
    func_01ffd504(M2C_FIELD(arg0, s16 *, 0x180));
    func_0201ea80(arg0, 0xA, 0);
    if (func_02075738(0, 0x400) != 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 4;
        M2C_FIELD(arg0, s8 *, 0x96) = 0;
        M2C_FIELD(arg0, s8 *, 0xA3) = 0;
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        func_020559cc(arg0, 0xD);
    }
}
