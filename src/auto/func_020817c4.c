/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02081790(void **);                     /* extern */
M2C_UNK func_020830b0();                            /* extern */
M2C_UNK func_02083128();                            /* extern */

void func_020817c4(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_020830b0(arg0);
        /* fallthrough */
        case 1:
            func_02081790(arg0);
            return;
        case 2:
            func_02083128(arg0);
            return;
    }
}
