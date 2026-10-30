/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a9c18();                            /* extern */
M2C_UNK func_020a9c90();                            /* extern */
M2C_UNK func_020b81b8(M2C_UNK, void *, M2C_UNK);    /* extern */

void func_020a9ebc(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0xC) {
        func_020a9c18();
    }
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0x14) {
        func_020a9c90();
        func_020b81b8(8, arg0 + 0x30, 0);
    }
}
