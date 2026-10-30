/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201f180();                            /* extern */
M2C_UNK func_0201f1c8();                            /* extern */

void func_0201f21c(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x93);
    if ((u32) temp_r1 <= 1U) {
        if (temp_r1 == 0) {
            func_0201f1c8(arg0);
            return;
        }
        func_0201f180(arg0);
    }
}
