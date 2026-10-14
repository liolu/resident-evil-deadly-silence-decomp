#include "m2c.h"
#include "engine.h"

void func_020174f0(s32 arg0) {
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(arg0, u16 *, 0xE) ^ 0x8000);
}
