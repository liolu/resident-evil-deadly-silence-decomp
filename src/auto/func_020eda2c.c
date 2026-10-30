/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020e48a0(s32, s32);                    /* extern */
s32 func_020ed964(s32, s32);                        /* extern */
s32 func_020ed96c(s32, s32);                        /* extern */

void func_020eda2c(s32 arg0) {
    s32 temp_r4;
    s32 var_r1;
    s32 var_r5;

    var_r5 = 0;
    do {
        temp_r4 = func_020ed964(arg0, var_r5);
        func_020e48a0(temp_r4, func_020ed96c(arg0, var_r5));
        var_r5 += 1;
    } while (var_r5 < 3);
    var_r1 = 0;
loop_3:
    if (M2C_FIELD((arg0 + (var_r1 * 4)), s32 *, 0x18) != 0) {
    loop_4:
        goto loop_4;
    }
    var_r1 += 1;
    if (var_r1 >= 4) {
        return;
    }
    goto loop_3;
}
