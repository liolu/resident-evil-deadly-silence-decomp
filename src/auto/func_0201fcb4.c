/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s16 func_0201fcb4(void *arg0) {
    s16 var_r3;

    var_r3 = 0;
    if (M2C_FIELD(arg0, u16 *, 0x188) & 1) {
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
        var_r3 = M2C_FIELD(arg0, s16 *, 0x180);
    }
    if ((s32) M2C_FIELD(arg0, s16 *, 0x18E) > 8) {
        M2C_FIELD(arg0, s16 *, 0x18E) = 8;
    }
    return var_r3;
}
