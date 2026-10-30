/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02084afc();                                /* extern */
s32 func_02087f48();                                /* extern */

s32 func_0207ce5c(void *arg0) {
    if (func_02084afc() != 0) {
        return 1;
    }
    if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x30) > 0xB00) {
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x1D0) != 0) {
        return 0;
    }
    return func_02087f48() & 1;
}
