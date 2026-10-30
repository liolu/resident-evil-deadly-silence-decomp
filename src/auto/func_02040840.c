/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */

void func_02040840(void *arg0) {
    func_01ffd504(0);
    func_02075738(1, 0x400);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
    if (M2C_FIELD(arg0, s16 *, 0xA8) == 0) {
        M2C_FIELD(arg0, s8 *, 0x90) = 1;
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
        M2C_FIELD(arg0, s8 *, 0x98) = 0x3F;
        M2C_FIELD(arg0, s8 *, 0x96) = 0;
    }
}
