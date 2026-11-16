/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 *func_020f811c(u8 *, s32);
s32 func_020f817c(u8 *);

void func_0200e66c(u8 *arg0, s32 arg1) {
    u8 *var_r6;

    var_r6 = arg0;
    goto find;
loop_body:
    if (var_r6[1] == arg1) {
        var_r6[2] = var_r6[2] | 1;
        return;
    }
    var_r6 = var_r6 + func_020f817c(var_r6);
find:
    var_r6 = func_020f811c(var_r6, 2);
    if (var_r6 != NULL) {
        goto loop_body;
    }
}
