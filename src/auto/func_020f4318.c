#include "m2c.h"
#include "engine.h"

void func_020f4318(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, u16 *, 0x10) = (u16) (M2C_FIELD(arg0, u16 *, 0x10) & ~1);
    M2C_FIELD(arg0, u16 *, 0x20) = (u16) (M2C_FIELD(arg0, u16 *, 0x20) & ~1);
    *(M2C_UNK *)arg1 = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 8) = 0;
    *(M2C_UNK *)arg2 = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
}
