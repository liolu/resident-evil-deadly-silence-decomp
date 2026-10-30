/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020914e4(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_0201f258(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xA8) == 0) {
        M2C_FIELD(arg0, u8 *, 0x91) = (u8) (M2C_FIELD(arg0, u8 *, 0x91) + 1);
        return;
    }
    func_020914e4(arg0 + 0x54, 6, 6);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
}
