/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_021093b0(M2C_UNK, s32, s32);

s32 func_020702c0(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    M2C_UNK var_r8;
    s32 temp_r0;

    var_r8 = arg0;
    var_r7 = arg1;
    var_r5 = arg2 & 0xFFFFF;
    var_r4 = 0x200;
    goto check;
loop_7:
    if (var_r5 > 0x200) {
        var_r6 = var_r4;
    } else {
        var_r6 = var_r5;
    }
    temp_r0 = func_021093b0(var_r8, var_r7, var_r6);
    if (temp_r0 != var_r6) {
        return 0;
    }
    var_r7 += temp_r0;
    var_r5 -= temp_r0;
check:
    if (var_r5 > 0) {
        goto loop_7;
    }
    return 1;
}
