/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_021124f4(M2C_UNK, void *, s32);            /* extern */
s32 func_0211282c();                                /* extern */
extern M2C_UNK data_02152e10;

s32 func_020e5c5c(M2C_UNK arg0) {
    u32 var_r6;
    M2C_UNK *var_r5;
    s32 temp_r4;

    temp_r4 = func_0211282c();
    var_r5  = &data_02152e10;
    var_r6  = 0;
loop_1:
    if (func_021124f4(arg0, (u8 *) var_r5 + 4, temp_r4) == 0) {
        return *((M2C_UNK *) ((s8 *) &data_02152e10 + (var_r6 * 0x10)));
    }
    var_r6 += 1;
    var_r5 = (M2C_UNK *) ((u8 *) var_r5 + 0x10);
    if (var_r6 >= 0x20U) {
        return 0;
    }
    goto loop_1;
}
