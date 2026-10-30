/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */

void func_02029ebc(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 2:
            M2C_FIELD(arg0, s8 *, 0x91) = 0;
            M2C_FIELD(arg0, s8 *, 0x92) = 0;
            M2C_FIELD(arg0, u8 *, 0x93) = 0U;
            return;
        case 0:
            M2C_FIELD(arg0, u8 *, 0x93) = 1U;
            M2C_FIELD(arg0, s8 *, 0xA2) = 0;
            M2C_FIELD(arg0, s8 *, 0xA3) = 0;
            M2C_FIELD(arg0, s8 *, 0xA0) = 0;
            M2C_FIELD(arg0, s8 *, 0x98) = 3;
        /* fallthrough */
        case 1:
            M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + func_02075738(1, 0x400));
            return;
    }
}
