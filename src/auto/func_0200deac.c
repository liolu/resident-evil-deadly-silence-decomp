/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u64 func_0211851c(s32, s32);
extern s32 data_021372cc;
extern s32 *data_021372d0;

s32 func_0200deac(void) {
    s32 *temp_r5;
    s32 temp_r3;
    s32 temp_r4;

    if (data_021372d0[4] == 1) {
        return 0;
    }
    data_021372d0[3] = 0;
    temp_r5          = data_021372d0;
    temp_r3          = temp_r5[0];
    temp_r4          = data_021372cc + (temp_r3 << 5);
    temp_r5[0]       = (s32) (func_0211851c(temp_r3 + 1, 0x20) >> 32);
    if (data_021372d0[1] == data_021372d0[0]) {
        data_021372d0[4] = 1;
    }
    data_021372d0[2] = data_021372d0[2] - 1;
    return temp_r4;
}
