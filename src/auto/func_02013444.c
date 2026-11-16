/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02013300(u8, u8, u8);

u8 func_02013444(u8 *arg0) {
    u8 *var_r5;
    s8 var_r4;

    var_r5 = arg0;
    var_r4 = 0;
    while (var_r5[3] != 0xFF) {
        if (func_02013300(var_r5[0], var_r5[1], var_r5[2]) != 0) {
            return (u8) var_r4;
        }
        var_r5 += 4;
        var_r4 = (s8) (var_r4 + 1);
    }
    return 0xFF;
}
