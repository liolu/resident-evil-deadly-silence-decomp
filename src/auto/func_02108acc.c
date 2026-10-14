#include "m2c.h"
#include "engine.h"

void func_02108acc(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r1;
    s32 var_r2;

    var_r1 = arg1;
    var_r2 = arg2;
    if (var_r2 == 0) {
        var_r1 = 0;
    } else if (var_r1 == 0) {
        var_r2 = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x48) = var_r1;
    M2C_FIELD(arg0, s32 *, 0x4C) = var_r2;
}
