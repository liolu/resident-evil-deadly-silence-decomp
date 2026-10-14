/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e6950();                            /* extern */
M2C_UNK func_0211035c(s8 *, M2C_UNK, M2C_UNK);      /* extern */

void func_020e6c20(s8 *arg0) {
    if (arg0 == NULL) {
        return;
    }
    func_020e6950();
    *arg0 = 0;
    func_0211035c(arg0, 0, 0x238);
}
