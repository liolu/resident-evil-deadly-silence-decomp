/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_020e8808(s32, s32);                    /* extern */

void func_020e7408(void *arg0, s32 arg1) {
    s32 var_r1;
    s32 var_r4;

    var_r1 = arg1;
    if (arg0 == NULL) {
        return;
    }
    if (var_r1 >= 0) {
        var_r1 = 0;
    }
    if (var_r1 <= -999) {
        var_r1 = -0x3E7;
    }
    M2C_FIELD(arg0, s32 *, 0x3C) = var_r1;
    var_r4                       = 0;
    if ((s32) M2C_FIELD(arg0, s8 *, 3) <= 0) {
        return;
    }
    do {
        func_020e8808(M2C_FIELD((arg0 + (var_r4 * 4)), s32 *, 0x48), M2C_FIELD(arg0, s32 *, 0x3C));
        var_r4 += 1;
    } while (var_r4 < (s32) M2C_FIELD(arg0, s8 *, 3));
}
