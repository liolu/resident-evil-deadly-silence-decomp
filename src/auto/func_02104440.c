#include "m2c.h"
#include "engine.h"

void func_02104440(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, volatile s16 *, 0) = 0;
    M2C_FIELD(arg0, volatile s16 *, 2) = 0;
    M2C_FIELD(arg0, volatile s32 *, 4) = arg1;
    M2C_FIELD(arg0, volatile s32 *, 8) = arg2;
    M2C_FIELD(arg0, volatile s32 *, 0xC) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x10) = 0;
}
