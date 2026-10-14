/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020dbf80(s32);                             /* extern */

s32 func_020df2d8(void *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return func_020dbf80(M2C_FIELD(arg0, s32 *, 4));
}
