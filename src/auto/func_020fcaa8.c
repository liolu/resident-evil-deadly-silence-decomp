/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern s32 data_02157340;

s32 func_020fcaa8(void) {
    s32 var_r0;
    s32 var_r3;

    var_r3 = 1;
    var_r0 = 0;
loop_1:
    if (!(data_02157340 & var_r3)) {
        data_02157340 |= var_r3;
        return var_r0;
    }
    var_r0 += 1;
    var_r3 *= 2;
    if (var_r0 >= 8) {
        return -1;
    }
    goto loop_1;
}
