/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e814c();                            /* extern */
M2C_UNK func_020e8548(s8 *);                        /* extern */

void func_020e840c(s8 *arg0) {
    if (arg0 == NULL) {
        return;
    }
    func_020e814c();
    if (*arg0 != 1) {
        return;
    }
    *arg0 = 0;
    func_020e8548(arg0);
}
