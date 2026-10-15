#include "engine.h"
#include "m2c.h"

void func_020fbd70(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0)    = (s32) M2C_FIELD(arg1, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 4)    = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) ((0x1000 - M2C_FIELD(arg1, s32 *, 0x18)) * M2C_FIELD(arg1, u16 *, 0x2C) * 8);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) ((0x1000 - M2C_FIELD(arg1, s32 *, 0x1C)) * M2C_FIELD(arg1, u16 *, 0x2E) * 8);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}
