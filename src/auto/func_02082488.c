/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020823b4();                            /* extern */

void func_02082488(void **arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 != M2C_FIELD(*arg0, u8 *, 0xA1)) {
        func_020823b4(arg0, arg1, arg2, arg3);
    }
}
