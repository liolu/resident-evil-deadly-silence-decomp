#include "m2c.h"
#include "engine.h"

void func_02020550(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 0xF;
    M2C_FIELD(arg0, s16 *, 0x18C) = 0;
    M2C_FIELD(arg0, s16 *, 0x18E) = 0;
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
}
