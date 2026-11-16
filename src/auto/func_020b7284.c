/* compiler: 1.2/sp2p3 */
#include "m2c.h"

u32 func_0200d958(u32, u32);

u32 func_020b7284(u32 arg0, u32 arg1) {
    u32 temp_r0;
    u32 var_r5;
    u32 var_r7;

    var_r7 = arg0;
    var_r5 = 0;
    goto check;
body:
    temp_r0 = func_0200d958(var_r7, 6);
    if (var_r5 < temp_r0) {
        var_r5 = temp_r0;
    }
    var_r7 += 1;
check:
    if (var_r7 <= arg1) {
        goto body;
    }
    return var_r5;
}
