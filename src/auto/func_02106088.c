#include "m2c.h"

void func_02106088(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_ip;

    var_ip = 0;
loop_1:
    if (var_ip < arg2) {
        u16 tmp                  = (u16) * (s16 *) (arg0 + var_ip);
        *(s16 *) (arg1 + var_ip) = (s16) tmp;
        var_ip += 2;
        goto loop_1;
    }
}
