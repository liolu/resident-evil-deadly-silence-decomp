/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020822dc();                                /* extern */

void func_020834dc(void *arg0) {
    void *temp_r1;

    if (func_020822dc() != 0) {
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
}
