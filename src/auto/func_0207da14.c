#include "engine.h"
#include "m2c.h"

void func_0207da14(s32 arg0) {
    s32 temp_r1;
    s32 var_r1;
    void *temp_r3;

    temp_r3                         = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r3, s32 *, 0x34) = (s32) (M2C_FIELD(temp_r3, s32 *, 0x34) + M2C_FIELD(arg0, s32 *, 0x1C8));
    temp_r1                         = M2C_FIELD(arg0, s32 *, 0x1C8);
    if (temp_r1 < 0x300) {
        var_r1 = temp_r1 + 0x40;
    } else {
        var_r1 = 0x300;
    }
    M2C_FIELD(arg0, s32 *, 0x1C8) = var_r1;
}
