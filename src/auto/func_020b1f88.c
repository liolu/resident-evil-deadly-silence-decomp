/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02053e90(u8);                              /* extern */

s32 func_020b1f88(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = func_02053e90(M2C_FIELD(arg0, u8 *, 1));
    return 0xE;
}
