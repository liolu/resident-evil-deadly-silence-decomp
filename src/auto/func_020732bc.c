#include "m2c.h"
#include "engine.h"

void func_020732bc(s32 arg0) {
    s16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s16 *, 0x10);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) (temp_r2 - 1);
    if (temp_r2 == 0) {
        M2C_FIELD(arg0, s8 *, 1) = 3;
    }
}
