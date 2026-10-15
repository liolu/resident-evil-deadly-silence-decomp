#include "engine.h"
#include "m2c.h"

void func_02050a30(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x91)   = 1;
    M2C_FIELD(arg0, u8 *, 8)      = (u8) (M2C_FIELD(arg0, u8 *, 8) & ~8);
    M2C_FIELD(arg0, s16 *, 0x18C) = 1;
}
