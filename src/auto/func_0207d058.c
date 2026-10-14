/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02088530();                                /* extern */

void func_0207d058(void **arg0) {
    void *temp_r1;

    if (func_02088530() != 0) {
        temp_r1 = *arg0;
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
    }
}
