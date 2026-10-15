#include "engine.h"
#include "m2c.h"

void func_02091a5c(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s8 *, 0) = (s8) ((u32) arg0 >> 0x18);
    M2C_FIELD(arg1, s8 *, 1) = (s8) ((u32) arg0 >> 0x10);
    M2C_FIELD(arg1, s8 *, 2) = (s8) ((u32) arg0 >> 8);
    M2C_FIELD(arg1, s8 *, 3) = (s8) arg0;
}
