/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02082bb8(void **);                     /* extern */
M2C_UNK func_02082c98();                            /* extern */
M2C_UNK func_02082d28();                            /* extern */

void func_02082ce0(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02082c98(arg0);
        /* fallthrough */
        case 1:
            func_02082bb8(arg0);
            return;
        case 2:
            func_02082d28(arg0);
            return;
    }
}
