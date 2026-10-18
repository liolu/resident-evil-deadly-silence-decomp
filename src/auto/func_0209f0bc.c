#include "m2c.h"

extern M2C_UNK data_02143cc0;

s32 func_0209f0bc(void) {
    s32 var_r0;

    var_r0 = 0;
    if ((s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF74) >= 0x3800) {
        var_r0 |= 2;
    }
    if ((s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) >= 0x2000) {
        var_r0 |= 1;
    }
    return var_r0;
}
