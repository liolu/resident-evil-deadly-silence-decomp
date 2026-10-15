/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_01ffbd98(M2C_UNK, s32, s32, s32, s32);     /* extern */

s16 func_020b5968(M2C_UNK arg0, void *arg1, s32 arg2) {
    if (func_01ffbd98(arg0, M2C_FIELD(arg1, u16 *, 0) + arg2, M2C_FIELD(arg1, u16 *, 2) + arg2,
                      M2C_FIELD(arg1, u16 *, 4) - arg2, M2C_FIELD(arg1, u16 *, 6) - arg2) == 0) {
        return (s16) (M2C_FIELD(arg1, u16 *, 0xA) & 0xFF00);
    }
    return -1;
}
