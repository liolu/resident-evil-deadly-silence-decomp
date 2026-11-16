#include "m2c.h"

s32 func_020049e8(s8 *arg0, s8 *arg1) {
    s32 var_r2;
    s8 *var_ip;
    s8 *var_r3;
    s8 temp_r0;
    s8 temp_r1;

    var_ip = arg0 + 0x20;
    var_r3 = arg1 + 0x10;
    var_r2 = 0xF;
loop:
    var_r2 -= 1;
    if (var_r2 > 0) {
        temp_r0 = *var_r3++;
        temp_r1 = *var_ip++;
        if (temp_r1 == temp_r0) {
            goto loop;
        }
    }
    if (var_r2 == 0) {
        return 1;
    }
    return 0;
}
