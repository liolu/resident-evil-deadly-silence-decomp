/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014dac(M2C_UNK, M2C_UNK);              /* extern */

s32 func_02088158(void) {
    u8 temp_r1;
    void *temp_r0;

    temp_r0 = func_02014dac(2, 0);
    if (temp_r0 == NULL) {
        return 0;
    }
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 0x16);
    if (temp_r1 == 2) {
        return 0;
    }
    if (temp_r1 == 1) {
        return 1;
    }
    if ((M2C_FIELD(temp_r0, u8 *, 0x19) == 1) && (M2C_FIELD(temp_r0, u8 *, 0x1A) != 0)) {
        return 1;
    }
    return 0;
}
