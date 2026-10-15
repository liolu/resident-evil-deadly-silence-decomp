#include "engine.h"
#include "m2c.h"

void func_020a9f90(M2C_UNK);

void func_020aa340(s32 arg0) {
    u8 temp_r3;

    M2C_FIELD(arg0, s8 *, 0x93) = 6;
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 3;
    temp_r3                     = M2C_FIELD(arg0, u8 *, 0x16B);
    M2C_FIELD(arg0, s8 *, 0xA1) = (s8) (((s32) (temp_r3 & 0x80) >> 7) + 0xE + (((s32) (temp_r3 & 0x20) >> 5) * 2));
    func_020a9f90(arg0);
}
