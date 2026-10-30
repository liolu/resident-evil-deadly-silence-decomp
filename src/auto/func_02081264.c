/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02082314();                                /* extern */
M2C_UNK func_020823b4(void *, u8, M2C_UNK, M2C_UNK); /* extern */

void func_02081264(void *arg0) {
    u8 temp_r1;
    void *temp_r2;

    if (func_02082314() != 0) {
        temp_r2 = M2C_FIELD(arg0, void **, 0);
        temp_r1 = M2C_FIELD(temp_r2, u8 *, 0x93);
        if (temp_r1 == M2C_FIELD(temp_r2, u8 *, 0xA1)) {
            M2C_FIELD(temp_r2, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r2, u8 *, 0x92) + 1);
            M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
            return;
        }
        func_020823b4(arg0, temp_r1, 0, 1);
    }
}
