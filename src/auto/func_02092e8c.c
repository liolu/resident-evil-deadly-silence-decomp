#include "engine.h"
#include "m2c.h"

void func_02092e8c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s16 *, 0xE)  = (s16) arg2;
    M2C_FIELD(arg0, s16 *, 0xC)  = (s16) arg3;
}
