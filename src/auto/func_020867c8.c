/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020182f0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_02091bd0(u32, s32);                    /* extern */
extern M2C_UNK data_027e007c;

void func_020867c8(s32 arg0, s32 arg1) {
    u32 var_r0;

    var_r0 = 0xFF;
    if (arg1 == 0xC) {
        func_020182f0(0, 0, 0, &data_027e007c, arg0, 0);
        var_r0 = 7;
    }
    if (var_r0 < 0x51U) {
        func_02091bd0(var_r0, arg0);
    }
}
