/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0209c840(u8, s32);

s32 func_0209c91c(u8 arg0, s32 arg1, s32 arg2) {
    u8 var_r7;
    u32 var_r4;

    var_r7 = arg0;
    for (var_r4 = 0; var_r4 < 4; var_r4++) {
        if (func_0209c840(var_r7, arg1) != 0) {
            return arg1 + (var_r7 * 2);
        }
        var_r7 += arg2;
    }
    return -1;
}
