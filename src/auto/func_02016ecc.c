#include "m2c.h"
#include "engine.h"

void func_02016ecc(s32 arg0) {
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) < 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0) = 0x2F;
    M2C_FIELD(arg0, s16 *, 0xE) = 0x4007;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (0 - (M2C_FIELD(arg0, s16 *, 0x2A) + M2C_FIELD(arg0, s32 *, 0x48)));
}
