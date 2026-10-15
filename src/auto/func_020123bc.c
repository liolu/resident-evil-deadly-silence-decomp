#include "engine.h"
#include "m2c.h"

void func_020123bc(s32 arg0, s32 arg1) {
    u8 temp_r3;

    temp_r3                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r3 - 1);
    if (temp_r3 == 0) {
        M2C_FIELD(arg0, s8 *, 5)     = 2;
        M2C_FIELD(arg1, u8 *, 0xE4)  = 0x28U;
        M2C_FIELD(arg1, s16 *, 0x12) = 0x3000;
    }
    M2C_FIELD(arg1, s32 *, 4)   = (s32) (M2C_FIELD(arg1, s32 *, 4) + 0x3000);
    M2C_FIELD(arg1, s16 *, 0xE) = (s16) (M2C_FIELD(arg1, s16 *, 0xE) - 0x180);
}
