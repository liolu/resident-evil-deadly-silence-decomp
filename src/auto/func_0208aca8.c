/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0208ace0(void *);                          /* extern */

s32 func_0208aca8(void *arg0) {
    s32 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x2C0) == 0) {
        return 0;
    }
    var_r0 = func_0208ace0(arg0 + 0x2B8);
    if (var_r0 == -1) {
        var_r0 = 0;
    }
    return var_r0;
}
