#include "m2c.h"

extern s32 data_02137298;

void func_0200a784(u32 arg0, s32 arg1) {
    if (arg0 >= 0x20U) {
        return;
    }
    M2C_FIELD((data_02137298 + (arg0 * 8)), s8 *, 0x1846) = (s8) (arg1 & 0x7F);
}
