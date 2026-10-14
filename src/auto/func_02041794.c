#include "m2c.h"
#include "engine.h"

void func_02041794(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) & ~2);
    M2C_FIELD(arg0, s8 *, 0x90) = 1;
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    M2C_FIELD(arg0, s8 *, 0x92) = 0;
    M2C_FIELD(arg0, s8 *, 0x93) = 0;
}
