#include "engine.h"
#include "m2c.h"

void func_020f31d8(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg1 - (u16) (((s32) M2C_FIELD(arg1, u16 *, 2) >> 8) & 0x7F));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + (arg1 + 0x10));
}
