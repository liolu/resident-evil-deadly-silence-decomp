/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02084a1c(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_02083f50(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s8 *, 0x1E) > 0) {
        func_02084a1c(arg0, 0, 0);
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) (M2C_FIELD(arg0, s8 *, 0x1E) - 1);
    }
}
