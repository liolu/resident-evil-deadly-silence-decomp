/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020df2d8(M2C_UNK);
void func_020df398(M2C_UNK, M2C_UNK);
M2C_UNK func_020df3c4(M2C_UNK);
void func_020e0b88(M2C_UNK, M2C_UNK);
void func_020e0da8(M2C_UNK, M2C_UNK);

void func_020e2c5c(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 8);
    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r4 == 0) {
        return;
    }
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2 = func_020df2d8(temp_r0);
    if (M2C_FIELD(arg0, s8 *, 2) == 4) {
        func_020e0b88(M2C_FIELD(arg0, s32 *, 8), 0x7FFFFFFF);
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 0x6C) == 0) {
        if (func_020df3c4(M2C_FIELD(arg0, s32 *, 4)) >= (s32) M2C_FIELD(arg0, s32 *, 0xC0)) {
            func_020df398(M2C_FIELD(arg0, s32 *, 4), -1);
        }
        func_020e0b88(M2C_FIELD(arg0, s32 *, 8), 0x7FFFFFFF);
        return;
    }
    func_020e0da8(temp_r4, (s32) (temp_r0_2 + ((u32) (temp_r0_2 >> 0xA) >> 0x15)) >> 0xB);
}
