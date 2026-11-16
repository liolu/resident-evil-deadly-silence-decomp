#include "m2c.h"

s32 func_0200d1f4(void *arg0, u32 arg1, s32 arg2) {
    s32 temp_r3;
    u32 temp_r2;
    s32 temp_r0;

    temp_r3 = *(s32 *) ((u8 *) arg0 + 0x88);
    temp_r2 = temp_r3 + arg2;
    if (temp_r2 == 0) {
        return 0;
    }
    if (arg1 >= *(u32 *) temp_r2) {
        return 0;
    }
    temp_r0 = *(s32 *) (temp_r2 + arg1 * 4 + 4);
    if (temp_r0 == 0) {
        return 0;
    }
    return temp_r3 + temp_r0;
}
