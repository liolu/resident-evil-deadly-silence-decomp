/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207fd38(void **);                     /* extern */
M2C_UNK func_020830b0();                            /* extern */
M2C_UNK func_02083128();                            /* extern */

void func_0207fd68(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_020830b0(arg0);
        /* fallthrough */
        case 1:
            func_0207fd38(arg0);
            return;
        case 2:
            func_02083128(arg0);
            return;
    }
}
