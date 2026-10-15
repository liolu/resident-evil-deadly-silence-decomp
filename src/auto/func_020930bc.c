#include "engine.h"
#include "m2c.h"

s32 func_020930bc(s32 arg0) {
    s32 var_r2;
    u8 temp_r1;

    var_r2                                                          = 0;
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 4) * 4)), s32 *, 0x18) = 0;
    temp_r1                                                         = M2C_FIELD(arg0, u8 *, 4);
    if (temp_r1 != 0) {
        var_r2                   = 1;
        M2C_FIELD(arg0, u8 *, 4) = (u8) (temp_r1 - 1);
    }
    return var_r2;
}
