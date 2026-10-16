#include "m2c.h"

void func_02106070(s16 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = 0;
loop_1:
    if (var_r3 < arg2) {
        *(s16 *) (arg1 + var_r3) = (s16) arg0;
        var_r3 += 2;
        goto loop_1;
    }
}
