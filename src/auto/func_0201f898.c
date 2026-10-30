/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201f7c8();                            /* extern */
M2C_UNK func_0201f834();                            /* extern */

void func_0201f898(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x92) == 0) {
        func_0201f834(arg0);
        return;
    }
    func_0201f7c8(arg0);
}
