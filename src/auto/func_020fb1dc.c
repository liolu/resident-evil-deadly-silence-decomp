#include "m2c.h"
#include "engine.h"

void func_020fb1dc(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x1000;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) ((0 - (M2C_FIELD(arg1, s32 *, 0x24) * M2C_FIELD(arg1, u16 *, 0x2C))) * 0x10);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg1, s32 *, 0x28) * M2C_FIELD(arg1, u16 *, 0x2E) * 0x10);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}
