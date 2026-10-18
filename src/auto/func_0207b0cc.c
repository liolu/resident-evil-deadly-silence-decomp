/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_0207b0cc(s32 arg0, u32 arg1) {
    s32 var_ip;
    s32 var_r3;

    var_r3 = 0x18;
    var_ip = 0;
    do {
        *(s8 *) (arg0 + var_ip) = (s8) (arg1 >> var_r3);
        var_ip += 1;
        var_r3 -= 8;
    } while (var_ip < 4);
}