/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02091014(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020b6874(M2C_UNK, M2C_UNK);            /* extern */

void func_0201f180(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0xF) {
        func_020b6874(2, 0);
    }
    if (func_02091014(0, 0x400, 5) != 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    }
}
