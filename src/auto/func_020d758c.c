/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d880c(M2C_UNK);                     /* extern */

void func_020d758c(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d880c(0xA);
        return;
    }
    func_020d880c(0);
}
