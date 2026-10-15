#include "engine.h"
#include "m2c.h"

void func_02015cc4(s32 arg0) {
    u8 temp_r1;

    M2C_FIELD(arg0, s8 *, 0x1E) = 0;
    temp_r1                     = M2C_FIELD(arg0, u8 *, 3);
    if (temp_r1 != 0) {
        M2C_FIELD(arg0, u8 *, 3) = (u8) (temp_r1 - 2);
    }
}
