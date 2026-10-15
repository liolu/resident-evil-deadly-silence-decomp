#include "engine.h"
#include "m2c.h"

void func_02012838(s32 arg0, s32 arg1) {
    u8 temp_r3;

    M2C_FIELD(arg1, s32 *, 8)    = (s32) (M2C_FIELD(arg1, s32 *, 8) - M2C_FIELD(arg1, s16 *, 0x12));
    M2C_FIELD(arg1, s16 *, 0x12) = (s16) (M2C_FIELD(arg1, s16 *, 0x12) - 2);
    if ((s32) M2C_FIELD(arg1, s16 *, 0x12) < 0) {
        M2C_FIELD(arg1, s16 *, 0x12) = 0;
    }
    temp_r3                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r3 - 1);
    if (temp_r3 != 0) {
        return;
    }
    M2C_FIELD(arg1, s16 *, 0x12) = 0x12C;
    M2C_FIELD(arg1, s16 *, 0x14) = 0x104;
    M2C_FIELD(arg1, u8 *, 0xE4)  = 0x32U;
    M2C_FIELD(arg0, s8 *, 5)     = 3;
}
