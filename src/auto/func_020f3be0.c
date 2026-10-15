#include "engine.h"
#include "m2c.h"

void func_020f3be0(s32 arg0) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + arg0);
}
