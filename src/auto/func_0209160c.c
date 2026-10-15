#include "engine.h"
#include "m2c.h"

void func_0209160c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s16 *, 0x2C) = (s16) (arg1 | (arg2 << 5) | (arg3 << 0xA));
}
