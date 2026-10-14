#include "m2c.h"
#include "engine.h"

void func_02010f9c(M2C_UNK);

void func_02012c6c(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s32 *, 0) = 0;
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s16 *, 0xC) = 0;
    M2C_FIELD(arg1, s16 *, 0xE) = 0;
    M2C_FIELD(arg1, s16 *, 0x10) = 0;
    M2C_FIELD(arg1, s16 *, 0xC) = 0;
    M2C_FIELD(arg1, s8 *, 0xE4) = 0x28;
    M2C_FIELD(arg1, s16 *, 0x12) = 0x3E8;
    func_02010f9c(arg1);
}
