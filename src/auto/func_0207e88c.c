/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207e7b4(void **);                     /* extern */
M2C_UNK func_020834cc();                            /* extern */
M2C_UNK func_02083514();                            /* extern */

void func_0207e88c(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02083514(arg0);
        /* fallthrough */
        case 1:
            func_0207e7b4(arg0);
            return;
        case 2:
            func_020834cc(arg0);
            return;
    }
}
