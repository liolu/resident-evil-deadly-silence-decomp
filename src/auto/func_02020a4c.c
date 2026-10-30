/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02020940(void *);                      /* extern */
M2C_UNK func_02020978(void *);                      /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */

void func_02020a4c(void *arg0) {
    u8 temp_r4;

    temp_r4 = M2C_FIELD(arg0, u8 *, 0xA2);
    func_02075738(1, 0x80);
    M2C_FIELD(arg0, u8 *, 0xA2) = temp_r4;
    if (M2C_FIELD(arg0, u8 *, 0x92) == 0) {
        func_02020978(arg0);
        return;
    }
    func_02020940(arg0);
}
