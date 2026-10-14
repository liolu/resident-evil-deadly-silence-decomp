#include "m2c.h"

s32 func_020ddb8c(void *arg0, s32 arg1, s16 *arg2) {
    s16 temp_r1_2;
    u16 temp_r1;
    u16 temp_r1_3;

    if (arg1 < 0x12) {
        return -1;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0);
    if ((u16) (s16) ((u8) ((s32) temp_r1 >> 8) | ((temp_r1 << 8) & 0xFF00)) != 0x8000) {
        return -2;
    }
    temp_r1_2 = M2C_FIELD(arg0, s16 *, 2);
    if ((s32) (s16) ((u8) (temp_r1_2 >> 8) | ((temp_r1_2 << 8) & 0xFF00)) < 0xE) {
        return -1;
    }
    temp_r1_3 = M2C_FIELD(arg0, u16 *, 0x10);
    *arg2 = (u8) ((s32) temp_r1_3 >> 8) | ((temp_r1_3 << 8) & 0xFF00);
    return 0;
}
