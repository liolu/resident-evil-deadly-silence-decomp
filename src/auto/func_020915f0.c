#include "engine.h"
#include "m2c.h"

void func_020915f0(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) arg1;
    M2C_FIELD(arg0, s16 *, 0x34) = (s16) arg2;
}
