/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020062ac(M2C_UNK, void *);             /* extern */

void func_020c0528(void *arg0, s32 arg1) {
    if ((arg1 >= -2) && (arg1 < 0x24)) {
        M2C_FIELD(arg0, s16 *, 8) = (s16) (arg1 + 0x11);
        func_020062ac(0, arg0);
    }
}
