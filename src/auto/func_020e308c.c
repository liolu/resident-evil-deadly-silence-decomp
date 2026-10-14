#include "m2c.h"

s32 func_020e308c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = 2;
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x20) = arg3;
    M2C_FIELD(arg0, s32 *, 0x24) = arg4;
    return 1;
}
