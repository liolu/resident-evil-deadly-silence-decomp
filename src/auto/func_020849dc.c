/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02084984();                              /* extern */
u32 func_020849ac();                                /* extern */

s32 func_020849dc(s32 arg0, void *arg1) {
    void *temp_r0;

    if (func_020849ac() >= 0x20U) {
        return 0;
    }
    temp_r0                   = func_02084984();
    M2C_FIELD(arg1, s16 *, 0) = (s16) M2C_FIELD(temp_r0, s16 *, 0xC);
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = (s16) M2C_FIELD(temp_r0, s16 *, 0xE);
    return 1;
}
