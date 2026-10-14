/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020dbf54(s32, M2C_UNK);                    /* extern */
s32 func_020dbf68(s32);                             /* extern */

s32 func_020df204(void *arg0, M2C_UNK arg1) {
    if ((func_020dbf68(M2C_FIELD(arg0, s32 *, 4)) > 0) && ((u32) (u8) (s8) (M2C_FIELD(arg0, s8 *, 1) - 2) <= 1U)) {
        return func_020dbf54(M2C_FIELD(arg0, s32 *, 4), arg1);
    }
    return -0x80;
}
