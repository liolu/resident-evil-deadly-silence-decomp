/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e8874(s32);                             /* extern */

s32 func_020e776c(void *arg0) {
    if (arg0 == NULL) {
        return -1;
    }
    return func_020e8874(M2C_FIELD(arg0, s32 *, 0x48));
}
