/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0201eb38(void *, s16, M2C_UNK);            /* extern */

s32 func_0201fba4(void *arg0) {
    s32 var_r2;

    if (((func_0201eb38(arg0, (s16) (M2C_FIELD(arg0, volatile s16 *, 0x182) << 0xA), 1) == 0) &&
         (M2C_FIELD(arg0, volatile s16 *, 0xA8) == 0)) ||
        (M2C_FIELD(arg0, volatile u16 *, 0x188) & 1)) {
        M2C_FIELD(arg0, volatile s8 *, 0x93)   = 4;
        M2C_FIELD(arg0, volatile s16 *, 0x180) = (s16) M2C_FIELD(arg0, volatile s16 *, 0x182);
        M2C_FIELD(arg0, volatile s16 *, 0xA8)  = 0x400;
        return 0;
    }
    if ((s32) M2C_FIELD(arg0, volatile s16 *, 0xA8) > 0) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    M2C_FIELD(arg0, volatile s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0xA8) - var_r2);
    return 0;
}
