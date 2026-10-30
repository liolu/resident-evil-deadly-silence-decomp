/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020adad0(s32);                         /* extern */
s32 func_020adcf8(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020b8210(M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */

void func_020a99ac(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
            M2C_FIELD(arg0, u8 *, 0x93)  = 1U;
            M2C_FIELD(arg0, s8 *, 0x98)  = 3;
            M2C_FIELD(arg0, s16 *, 0xA6) = 0;
            func_020b8210(3, 0, arg0 + 0x30, 0);
            M2C_FIELD(arg0, s8 *, 0xA1) = 1;
            func_020adad0(0x8061);
        /* fallthrough */
        case 1:
            if (func_020adcf8(0, 0x400) != 0) {
                M2C_FIELD(arg0, s8 *, 0x90) = 1;
                M2C_FIELD(arg0, s8 *, 0x91) = 0;
                M2C_FIELD(arg0, s8 *, 0x92) = 0;
                M2C_FIELD(arg0, u8 *, 0x93) = 0U;
                M2C_FIELD(arg0, s8 *, 0x96) = 0;
            }
            return;
    }
}
