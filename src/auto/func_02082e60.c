/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02082e2c();                            /* extern */
M2C_UNK func_020834cc();                            /* extern */
M2C_UNK func_020834dc(void **);                     /* extern */

void func_02082e60(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02082e2c(arg0);
        /* fallthrough */
        case 1:
            func_020834dc(arg0);
            return;
        case 2:
            func_020834cc(arg0);
            return;
    }
}
