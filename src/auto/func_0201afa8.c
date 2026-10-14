/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0201893c(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */

void func_0201afa8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xA1) = 9;
    func_0205597c(8);
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s8 *, 0xA2) = 0;
        M2C_FIELD(arg0, s8 *, 0xA3) = 0;
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
    }
    func_0201893c(arg0, 1, 0x400);
}
