/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c0070(void *, void *);              /* extern */

void func_020c0090(void *arg0) {
    u8 temp_r2;
    void *temp_r1;
    void *var_r1;

    M2C_FIELD(arg0, u8 *, 0) = (u8) (M2C_FIELD(arg0, u8 *, 0) - 1);
    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        temp_r1 = M2C_FIELD(arg0, void **, 0x10);
        temp_r2 = M2C_FIELD(temp_r1, u8 *, 2);
        var_r1  = temp_r1 + 4;
        if (temp_r2 != 0) {
            var_r1 -= temp_r2 * 4;
        }
        func_020c0070(arg0, var_r1);
    }
}
