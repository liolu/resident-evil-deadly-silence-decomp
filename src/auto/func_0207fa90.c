/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207f8bc();                            /* extern */
M2C_UNK func_0207f8d8();                            /* extern */
M2C_UNK func_0208014c(void **);                     /* extern */

void func_0207fa90(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_0207f8d8(arg0);
        /* fallthrough */
        case 1:
            func_0208014c(arg0);
            return;
        case 2:
            func_0207f8bc(arg0);
            return;
    }
}
