#include "m2c.h"

s32 func_020dd4e8(void *arg0, s32 arg1, s16 *arg2) {
    s16 temp_r1_2;
    u16 temp_r1;

    if (arg1 < 0x10) {
        return -1;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0);
    if ((u16) (s16) ((u8) ((s32) temp_r1 >> 8) | ((temp_r1 << 8) & 0xFF00)) != 0x8001) {
        return -2;
    }
    temp_r1_2 = M2C_FIELD(arg0, s16 *, 2);
    *arg2     = (u8) (temp_r1_2 >> 8) | ((temp_r1_2 << 8) & 0xFF00);
    *arg2 += 4;
    return 0;
}
