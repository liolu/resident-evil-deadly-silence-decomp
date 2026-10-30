/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a9c90();                            /* extern */
M2C_UNK func_020b81b8(M2C_UNK, void *, M2C_UNK);    /* extern */

void func_020a9e8c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0xF) {
        func_020a9c90();
        func_020b81b8(0xC, arg0 + 0x30, 0);
    }
}
