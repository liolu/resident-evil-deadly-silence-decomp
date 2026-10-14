#include "m2c.h"
#include "engine.h"

void func_0201289c(s32 arg0, s32 arg1) {
    u8 temp_r3;

    temp_r3 = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r3 - 1);
    if (temp_r3 != 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 5) = 5;
    M2C_FIELD(arg1, u8 *, 0xE4) = 0x50U;
    M2C_FIELD(arg1, s16 *, 0x12) = 0x1E;
}
