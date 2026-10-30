/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a04b8();                            /* extern */

void func_020a0490(void *arg0, s32 arg1, u8 arg2) {
    if (arg2 != M2C_FIELD(arg0, u8 *, 0xA1)) {
        M2C_FIELD(arg0, u8 *, 0xA1) = arg2;
        func_020a04b8(arg0, arg1);
    }
}
