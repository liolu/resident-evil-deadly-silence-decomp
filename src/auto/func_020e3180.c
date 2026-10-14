#include "m2c.h"
#include "engine.h"

void func_020e3180(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x28) = (s16) M2C_FIELD(arg1, s16 *, 0);
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16) M2C_FIELD(arg2, s16 *, 0);
    M2C_FIELD(arg0, s16 *, 0x2C) = (s16) M2C_FIELD(arg1, s16 *, 2);
    M2C_FIELD(arg0, s16 *, 0x2E) = (s16) M2C_FIELD(arg2, s16 *, 2);
}
