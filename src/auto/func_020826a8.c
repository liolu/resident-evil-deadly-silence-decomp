/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020825f8();                            /* extern */
M2C_UNK func_02082610(void **);                     /* extern */
M2C_UNK func_02082690();                            /* extern */

void func_020826a8(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02082690(arg0);
        /* fallthrough */
        case 1:
            func_02082610(arg0);
            return;
        case 2:
            func_020825f8(arg0);
            return;
    }
}
