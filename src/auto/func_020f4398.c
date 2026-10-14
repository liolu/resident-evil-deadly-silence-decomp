#include "m2c.h"
#include "engine.h"

void func_020f4398(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    M2C_FIELD(arg0, s8 *, 0x24) = (s8) arg3;
    M2C_FIELD(arg0, s8 *, 0x25) = (s8) arg4;
}
