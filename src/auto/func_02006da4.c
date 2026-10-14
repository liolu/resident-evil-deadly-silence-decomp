/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210b1c4(M2C_UNK);                         /* extern */
s32 func_0210b1dc(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
extern void *data_02137298;
extern M2C_UNK func_0200736c;

s32 func_02006da4(s32 arg0) {
    s32 var_r0;
    s32 var_r0_2;

    switch (arg0) {                                 /* irregular */
    case 0:
        var_r0_2 = func_0210b1c4(0);
        if (var_r0_2 == 0) {
            M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~2);
            M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~4);
        }
        break;
    case 1:
        var_r0_2 = func_0210b1dc(0, &func_0200736c, 0);
        break;
    default:
        var_r0_2 = 2;
        break;
    }
    if (var_r0_2 != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return 0 - var_r0;
}
