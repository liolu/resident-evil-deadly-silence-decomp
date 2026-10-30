/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d764(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_0200d924(s32, s32);                    /* extern */
s32 func_0200d9e0(s32);                             /* extern */
M2C_UNK func_020b7814();                            /* extern */
M2C_UNK func_020b7de8(s32);                         /* extern */
s32 func_020b86e8();                                /* extern */
extern M2C_UNK data_0213ac6c;

void func_020b7e4c(s32 arg0, s32 arg1) {
    s32 temp_r4;

    temp_r4 = (arg0 * 0xC) + (s32) &data_0213ac6c;
    func_020b7814();
    func_020b7de8(arg0);
    if (func_0200d9e0(arg1) > 0) {
        M2C_FIELD(temp_r4, s32 *, 8) = func_020b86e8();
        if (M2C_FIELD(temp_r4, s32 *, 8) != 0) {
            M2C_FIELD(temp_r4, s32 *, 4) = arg1;
            func_0200d924(arg1, M2C_FIELD(temp_r4, s32 *, 8));
            func_0200d764(arg1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        M2C_FIELD(temp_r4, s8 *, 1) = 1;
        M2C_FIELD(temp_r4, s8 *, 0) = 1;
    }
}
