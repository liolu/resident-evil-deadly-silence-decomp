/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02085144();                            /* extern */

void func_02083964(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 4) != 4) {
        func_02085144(arg0);
        M2C_FIELD(arg0, u8 *, 4) = 4U;
    }
}
