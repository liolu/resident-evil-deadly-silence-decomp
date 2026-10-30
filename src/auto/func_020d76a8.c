/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d6c34();                            /* extern */
s32 func_020d7664();                                /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */

void func_020d76a8(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d6c34();
        return;
    }
    if (func_020d7664() == 0) {
        func_020d880c(9);
    }
}
