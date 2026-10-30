/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02053d50(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_020a04f0(void *, M2C_UNK);             /* extern */

void func_020267cc(M2C_UNK arg0) {
    void *temp_r0;

    temp_r0 = func_02053d50(0xFF, arg0);
    if (temp_r0 != NULL) {
        func_020a04f0(temp_r0, 0xA);
        M2C_FIELD(temp_r0, s8 *, 9) = 0x18;
    }
}
