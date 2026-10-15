#include "engine.h"
#include "m2c.h"

void func_020e0d10(s32 arg0) {
    M2C_FIELD(arg0, volatile s32 *, 0x34) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x4C) = 0;
    if (M2C_FIELD(arg0, volatile s32 *, 0x14) == 0) {
        M2C_FIELD(arg0, volatile s8 *, 1) = 3;
    } else {
        M2C_FIELD(arg0, volatile s8 *, 1) = 2;
    }
    M2C_FIELD(arg0, volatile s8 *, 2)     = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x24) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x28) = 0;
    M2C_FIELD(arg0, volatile s8 *, 0x47)  = 1;
}
