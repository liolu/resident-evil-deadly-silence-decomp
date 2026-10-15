/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_02012484(s32 arg0, s32 arg1) {
    u8 temp_r1;

    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0xF) {
        func_0206fcf8(0, 1, 1, 0x100);
    }
    temp_r1                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1 - 1);
    if (temp_r1 == 0) {
        M2C_FIELD(arg0, s8 *, 4) = 2;
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0) + 0x2000);
}
