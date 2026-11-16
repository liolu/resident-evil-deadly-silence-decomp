#include "m2c.h"

void func_020b11f8(s8 *arg0, s8 *arg1) {
    s8 *var_r0;
    s8 *var_r1;
    s8 temp_r2;

    var_r0 = arg0;
    var_r1 = arg1;
    goto loop_check1;
loop_body1:
    var_r0 += 1;
loop_check1:
    if (*var_r0 != 0) {
        goto loop_body1;
    }
    goto loop_check2;
loop_body2:
    temp_r2 = *var_r1++;
    *var_r0 = temp_r2;
    var_r0 += 1;
loop_check2:
    if (*var_r1 != 0) {
        goto loop_body2;
    }
    *var_r0 = 0;
}
