/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */

void func_02029f30(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, u8 *, 0x93) = 1U;
            M2C_FIELD(arg0, s8 *, 0xA2) = 0;
            M2C_FIELD(arg0, s8 *, 0xA3) = 0;
            M2C_FIELD(arg0, s8 *, 0xA0) = 0;
            M2C_FIELD(arg0, s8 *, 0x98) = 3;
        /* fallthrough */
        case 1:
            func_02075738(1, 0x400);
            return;
    }
}
