#include "engine.h"
#include "m2c.h"

s32 func_020f42e4(s32 arg0) {
    s32 temp_r2;

    M2C_FIELD(arg0, u16 *, 0x32) = (u16) (M2C_FIELD(arg0, u16 *, 0x32) & ~1);
    temp_r2                      = M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    return temp_r2;
}
