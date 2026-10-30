/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207cf1c();                            /* extern */
M2C_UNK func_0207cf34();                            /* extern */
M2C_UNK func_02082afc();                            /* extern */

void func_0207cf4c(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_0207cf34(arg0);
            return;
        case 1:
            func_02082afc(arg0);
            return;
        case 2:
            func_0207cf1c(arg0);
            return;
    }
}
