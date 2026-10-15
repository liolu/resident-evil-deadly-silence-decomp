/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020124e4(s32 arg0, s32 arg1) {
    u8 temp_r3;

    temp_r3                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r3 - 1);
    if (temp_r3 == 0) {
        M2C_FIELD(arg0, s8 *, 5)    = 2;
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x3CU;
    }
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + 0x3000);
    M2C_FIELD(arg1, s32 *, 8) = (s32) (M2C_FIELD(arg1, s32 *, 8) - 0x3000);
}
