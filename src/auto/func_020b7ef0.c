/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d6a8(M2C_UNK, s16, M2C_UNK);       /* extern */
extern M2C_UNK data_0213ac6c;

void func_020b7ef0(s32 arg0) {
    s32 temp_r1;
    s32 temp_r4;

    temp_r4 = (arg0 * 0xC) + (s32) &data_0213ac6c;
    temp_r1 = M2C_FIELD(temp_r4, s32 *, 4);
    if ((temp_r1 != 0) && (M2C_FIELD(temp_r4, u8 *, 0) != 0)) {
        func_0200d6a8(-1, (s16) temp_r1, 0);
        M2C_FIELD(temp_r4, s8 *, 1) = 0;
        M2C_FIELD(temp_r4, u8 *, 0) = 0U;
    }
}
