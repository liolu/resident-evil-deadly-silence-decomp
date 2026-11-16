/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020cd394(u32, s32);
extern M2C_UNK data_0213b890;

s32 func_020cd71c(void) {
    u32 var_r5;
    s32 var_r4;
    s32 t;

    var_r4 = var_r5 = 0;
    goto check;
loop_4:
    t = func_020cd394(var_r5, var_r4);
    if (t != M2C_FIELD((M2C_FIELD(&data_0213b890, void **, 0x4C) + var_r5), u8 *, 8)) {
        return 0;
    }
    var_r5 = (u32) (u8) (var_r5 + 1);
check:
    if (var_r5 < (u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x12)) {
        goto loop_4;
    }
    return 1;
}
