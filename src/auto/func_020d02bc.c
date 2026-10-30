/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020cffb0(void *, M2C_UNK);             /* extern */

void func_020d02bc(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 3) == 0) {
        M2C_FIELD(arg0, u8 *, 3) = 1U;
        func_020cffb0(arg0, 0);
    }
}
