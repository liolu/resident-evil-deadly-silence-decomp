#include "m2c.h"
#include "engine.h"

void func_020e314c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s16 *, 0x34) = (s16) arg1;
    M2C_FIELD(arg0, s16 *, 0x36) = (s16) arg2;
    M2C_FIELD(arg0, s16 *, 0x38) = (s16) arg3;
}
