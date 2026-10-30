/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02077264(void *);                      /* extern */

void func_0207729c(void **arg0) {
    void *temp_r2;

    temp_r2 = *arg0;
    *arg0   = NULL;
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, u8 *, 2) = (u8) (M2C_FIELD(temp_r2, u8 *, 2) - 1);
        if (M2C_FIELD(temp_r2, u8 *, 2) == 0) {
            func_02077264(temp_r2);
        }
    }
}
