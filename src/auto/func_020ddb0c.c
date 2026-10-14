/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020ddb0c(void *arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    s16 temp_r1_2;
    u16 temp_r1;

    if (arg1 < 0x14) {
        return -1;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0);
    if ((u16) (s16) ((u8) ((s32) temp_r1 >> 8) | ((temp_r1 << 8) & 0xFF00)) != 0x8000) {
        return -2;
    }
    temp_r1_2 = M2C_FIELD(arg0, s16 *, 2);
    if ((s32) (s16) ((u8) (temp_r1_2 >> 8) | ((temp_r1_2 << 8) & 0xFF00)) < 0x10) {
        return -1;
    }
    *arg2 = M2C_FIELD(arg0, u8 *, 0x12);
    *arg3 = M2C_FIELD(arg0, u8 *, 0x13);
    return 0;
}
