#include "engine.h"
#include "m2c.h"

void func_02091ab8(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s8 *, 0) = (s8) (((u32) arg0 >> 0x1B) & 0x1F);
    M2C_FIELD(arg1, s8 *, 1) = (s8) (((u32) arg0 >> 0x13) & 0x1F);
    M2C_FIELD(arg1, s8 *, 2) = (s8) (((u32) arg0 >> 0xB) & 0x1F);
    M2C_FIELD(arg1, s8 *, 3) = (s8) (((u32) arg0 >> 3) & 0x1F);
}
