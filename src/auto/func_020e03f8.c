#include "engine.h"
#include "m2c.h"

s32 func_020e03f8(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x18) = arg2;
    return 1;
}
