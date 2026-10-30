/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02082314();                                /* extern */
M2C_UNK func_020823b4(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_02080e84(void *arg0) {
    void *temp_r1;

    if (func_02082314() != 0) {
        func_020823b4(arg0, 0x17, 0, 1);
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
}
