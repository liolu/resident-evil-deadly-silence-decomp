/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014dac(M2C_UNK, u8);                   /* extern */

void func_02088264(u8 arg0) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_02014dac(3, arg0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 0x16) = 1;
        temp_r0_2                      = func_02014dac(3, (u8) (arg0 + 1));
        if (temp_r0_2 != NULL) {
            M2C_FIELD(temp_r0_2, s8 *, 0x16) = 1;
        }
    }
}
