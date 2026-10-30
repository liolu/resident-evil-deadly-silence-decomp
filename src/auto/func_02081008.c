/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02080f5c(void **);                     /* extern */
M2C_UNK func_02080fd8();                            /* extern */
M2C_UNK func_02082d28();                            /* extern */

void func_02081008(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02080fd8(arg0);
        /* fallthrough */
        case 1:
            func_02080f5c(arg0);
            return;
        case 2:
            func_02082d28(arg0);
            return;
    }
}
