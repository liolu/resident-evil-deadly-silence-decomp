/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0202075c();                            /* extern */
M2C_UNK func_0202085c();                            /* extern */

void func_0202090c(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x92);
    if ((u32) temp_r1 <= 1U) {
        if (temp_r1 == 0) {
            func_0202085c(arg0);
            return;
        }
        func_0202075c(arg0);
    }
}
