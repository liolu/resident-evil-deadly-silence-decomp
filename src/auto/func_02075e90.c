#include "m2c.h"
#include "engine.h"

void func_02075e90(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (s16) arg1;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (s16) arg2;
}
