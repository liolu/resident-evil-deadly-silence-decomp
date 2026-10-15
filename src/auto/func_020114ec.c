/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020114ec(s32 arg0, s32 arg1) {
    u8 temp_r3;

    M2C_FIELD(arg1, s32 *, 0)   = (s32) (M2C_FIELD(arg1, s32 *, 0) + 0x219A);
    temp_r3                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r3 - 1);
    if (temp_r3 != 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 5)     = 1;
    M2C_FIELD(arg1, u8 *, 0xE4)  = 0x46U;
    M2C_FIELD(arg1, s16 *, 0x18) = 0x180;
    M2C_FIELD(arg1, s8 *, 0xEB)  = 1;
}
