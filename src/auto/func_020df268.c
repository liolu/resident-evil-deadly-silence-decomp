/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020dbf60(s32);                             /* extern */
s32 func_020dbf68(s32);                             /* extern */

s32 func_020df268(void *arg0) {
    if ((func_020dbf68(M2C_FIELD(arg0, s32 *, 4)) > 0) && ((u32) (u8) (s8) (M2C_FIELD(arg0, s8 *, 1) - 2) <= 1U)) {
        return func_020dbf60(M2C_FIELD(arg0, s32 *, 4));
    }
    return 0;
}
