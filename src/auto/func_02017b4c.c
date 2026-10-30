/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02016a94();                            /* extern */
M2C_UNK func_02017bac(void *);                      /* extern */

void func_02017b4c(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 7);
    if (temp_r1 != 0) {
        M2C_FIELD(arg0, u8 *, 7) = (u8) (temp_r1 - 1);
        return;
    }
    func_02016a94(arg0);
    func_02017bac(arg0);
}
