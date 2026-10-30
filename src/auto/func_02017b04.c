/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02016a94();                            /* extern */

void func_02017b04(void *arg0) {
    u8 temp_r2;

    temp_r2                  = M2C_FIELD(arg0, u8 *, 7);
    M2C_FIELD(arg0, u8 *, 7) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        func_02016a94(arg0);
        M2C_FIELD(arg0, s8 *, 3)     = 0x1E;
        M2C_FIELD(arg0, s16 *, 0x28) = (s16) (M2C_FIELD(arg0, s16 *, 0x28) - 0xFA);
    }
}
