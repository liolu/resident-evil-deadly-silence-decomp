/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d564(M2C_UNK, s32, u32, M2C_UNK);  /* extern */
M2C_UNK func_0200d5a0(M2C_UNK, s16, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK data_02123a76;
extern M2C_UNK data_0213ac6c;

void func_020b7be4(s32 arg0, u32 arg1) {
    s32 temp_r4;

    if (arg1 <= 0x190U) {
        temp_r4 = (arg0 * 0xC) + (s32) &data_0213ac6c;
        func_0200d564(-1, M2C_FIELD(temp_r4, s32 *, 4), arg1, 4);
        func_0200d5a0(-1, (s16) M2C_FIELD(temp_r4, s32 *, 4), 0, 0x10000, 0, 0, 0, 0, 0,
                      (s32) * ((s16 *) ((s8 *) &data_02123a76 + (arg1 * 2))));
    }
}
