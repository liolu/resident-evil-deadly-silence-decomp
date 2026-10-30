/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c0090(void *);                      /* extern */

void func_020c00d4(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 5);
    if ((temp_r1 == 0) || (temp_r1 != 1) || (M2C_FIELD(arg0, u8 *, 0) != 0)) {
        func_020c0090(arg0 + 4);
    }
}
