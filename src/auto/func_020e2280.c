/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020e0de8(M2C_UNK);
M2C_UNK func_020e6848(M2C_UNK);

void func_020e2280(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = M2C_FIELD(arg0, s32 *, 8);
    if ((temp_r0 != 0) && (func_020e0de8(temp_r0) == 4)) {
        M2C_FIELD(arg0, s16 *, 0x60) = -1;
        M2C_FIELD(arg0, s8 *, 1)     = 6;
    }
    temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x94);
    if (temp_r0_2 == 0) {
        return;
    }
    if (func_020e6848(temp_r0_2) == 3) {
        M2C_FIELD(arg0, s16 *, 0x60) = -1;
        M2C_FIELD(arg0, s8 *, 1)     = 6;
    }
}
