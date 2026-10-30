/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d820(s32, M2C_UNK);                /* extern */
M2C_UNK func_020b86d0(s32);                         /* extern */
extern M2C_UNK data_0213abcc;

void func_020b83e0(s32 arg0) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = (M2C_UNK *) ((s8 *) &data_0213abcc + (arg0 * 8));
    temp_r0 = *((M2C_UNK *) ((s8 *) &data_0213abcc + (arg0 * 8)));
    if ((temp_r0 != 0) && (M2C_FIELD(temp_r4, s32 *, 4) != 0)) {
        func_0200d820(temp_r0, 6);
        func_020b86d0(M2C_FIELD(temp_r4, s32 *, 4));
        M2C_FIELD(temp_r4, s32 *, 0) = 0;
        M2C_FIELD(temp_r4, s32 *, 4) = 0;
    }
}
