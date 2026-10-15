#include "engine.h"
#include "m2c.h"

void func_020dc05c(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x78) = arg1;
    M2C_FIELD(arg0, s32 *, 0x7C) = arg2;
}
