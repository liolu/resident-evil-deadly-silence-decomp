#include "engine.h"
#include "m2c.h"

void func_020f28c8(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0)   = 0;
    M2C_FIELD(arg0, s32 *, 4)   = 0;
    M2C_FIELD(arg0, s16 *, 8)   = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) arg1;
}
