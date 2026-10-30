/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02083128();                            /* extern */
M2C_UNK func_0208326c(void **);                     /* extern */
M2C_UNK func_02083454();                            /* extern */

void func_02083484(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02083454(arg0);
        /* fallthrough */
        case 1:
            func_0208326c(arg0);
            return;
        case 2:
            func_02083128(arg0);
            return;
    }
}
