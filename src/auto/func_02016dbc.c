/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020153a4();                            /* extern */

void func_02016dbc(void *arg0) {
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) >= 0) {
        func_020153a4(arg0);
        M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(arg0, u16 *, 0xE) | 0x4007);
    }
}
