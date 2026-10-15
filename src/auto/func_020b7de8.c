/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200d6a8(M2C_UNK, s16, M2C_UNK);       /* extern */
M2C_UNK func_0200d8a4(s32);                         /* extern */
M2C_UNK func_020b86d0();                            /* extern */
extern M2C_UNK data_0213ac6c;

void func_020b7de8(s32 arg0) {
    s32 temp_r4;

    temp_r4 = (arg0 * 0xC) + (s32) &data_0213ac6c;
    func_0200d6a8(-1, (s16) M2C_FIELD(temp_r4, s32 *, 4), 0);
    if (M2C_FIELD(temp_r4, s32 *, 8) != 0) {
        func_020b86d0();
        M2C_FIELD(temp_r4, s32 *, 8) = 0;
        func_0200d8a4(M2C_FIELD(temp_r4, s32 *, 4));
    }
    M2C_FIELD(temp_r4, s32 *, 4) = 0;
    M2C_FIELD(temp_r4, s8 *, 1)  = 0;
    M2C_FIELD(temp_r4, s8 *, 0)  = 0;
}
