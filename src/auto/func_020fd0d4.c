/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210669c(s32, M2C_UNK);                /* extern */

void func_020fd0d4(void *arg0, s32 arg1, M2C_UNK arg2) {
    if (arg1 > (s32) (M2C_FIELD(arg0, s32 *, 0x48) - 1)) {
        return;
    }
    func_0210669c(1 << M2C_FIELD((arg0 + arg1), u8 *, 0x4C), arg2);
}
