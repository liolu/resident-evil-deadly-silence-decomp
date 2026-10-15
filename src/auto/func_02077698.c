#include "engine.h"
#include "m2c.h"

void func_02077698(s32 arg0) {
    u16 temp_r2;

    temp_r2                   = M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 6) = (u16) (temp_r2 + 1);
    if ((u32) temp_r2 >= 0x78U) {
        M2C_FIELD(arg0, s8 *, 0) = 1;
    }
}
