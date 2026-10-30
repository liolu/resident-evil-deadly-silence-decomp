/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02082798(void **);                     /* extern */
M2C_UNK func_020827f8();                            /* extern */
M2C_UNK func_020834cc();                            /* extern */

void func_0208280c(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_020827f8(arg0);
        /* fallthrough */
        case 1:
            func_02082798(arg0);
            return;
        default:
            func_020834cc(arg0);
            return;
    }
}
