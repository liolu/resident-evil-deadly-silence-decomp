/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */

void func_0204f934(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x94) = -1;
    if (M2C_FIELD(arg0, s16 *, 0xA8) != 0) {
        func_02075738(1, 0x100);
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
    }
}
