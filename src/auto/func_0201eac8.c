/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0201eb38(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s8 func_0201eac8(M2C_UNK arg0, M2C_UNK arg1, s8 arg2) {
    s32 temp_r4;
    s8 temp_r0;

    temp_r4 = func_0201eb38(arg0, 0x400, arg1);
    temp_r0 = 0 - func_0201eb38(arg0, -0x400, arg1);
    if ((temp_r4 != 0) && (temp_r0 != 0)) {
        return arg2;
    }
    return (s8) (temp_r4 + temp_r0);
}
