/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014e00(M2C_UNK);                       /* extern */

void func_020882ac(s8 arg0) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_02014e00(3);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 0x15) = arg0;
        temp_r0_2                      = func_02014e00(3);
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0x15) = (s8) (arg0 + 1);
        }
    }
}
