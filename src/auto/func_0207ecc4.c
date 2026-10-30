/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020822dc();                                /* extern */
M2C_UNK func_02082488(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02084c40(void *, M2C_UNK);             /* extern */

void func_0207ecc4(void *arg0) {
    void *temp_r1;

    if (func_020822dc() != 0) {
        if (!(M2C_FIELD(arg0, u8 *, 5) & 1)) {
            func_02082488(arg0, 2, 0, 1);
            func_02084c40(arg0, 0x800);
        }
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
}
