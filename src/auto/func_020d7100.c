/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
M2C_UNK func_02105528();                            /* extern */

void func_020d7100(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) == 8) {
        func_020d880c(9);
        func_02105528();
    }
}
