#include "m2c.h"
#include "engine.h"

s32 func_020f3180(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    M2C_FIELD(arg1, s32 *, 8) = arg2;
    if (arg2 != 0) {
        var_r3 = M2C_FIELD(arg2, s32 *, 0xC);
        M2C_FIELD(arg2, s32 *, 0xC) = arg1;
    } else {
        var_r3 = M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0) = arg1;
    }
    M2C_FIELD(arg1, s32 *, 0xC) = var_r3;
    if (var_r3 != 0) {
        M2C_FIELD(var_r3, s32 *, 8) = arg1;
    } else {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
    }
    return arg1;
}
