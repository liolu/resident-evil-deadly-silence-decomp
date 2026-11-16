/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0200d350(M2C_UNK);

s32 func_020b7318(s32 arg0) {
    s32 var_r0;

    switch (arg0) {
        case 0:
            var_r0 = 0;
            break;
        case 1:
            var_r0 = 2;
            break;
        case 2:
            var_r0 = 3;
            break;
        default:
            return 0;
    }
    return func_0200d350(var_r0);
}
