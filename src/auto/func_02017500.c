/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02016a94();                            /* extern */

void func_02017500(void *arg0) {
    u8 temp_r2;

    temp_r2                  = M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg0, u8 *, 6) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        func_02016a94();
    }
}
