#include "m2c.h"
#include "engine.h"

void func_020857ac(s32 arg0) {
    M2C_FIELD(*(M2C_UNK *)arg0, s32 *, 0xC) = (s32) (arg0 + 0x10);
    M2C_FIELD(*(M2C_UNK *)arg0, s16 *, 6) = 0x600;
    M2C_FIELD(*(M2C_UNK *)arg0, s8 *, 8) = 1;
}
