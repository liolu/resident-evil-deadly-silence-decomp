/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void func_020408a0(void *arg0) {
    if (func_0209109c(0, 0x400, 5) != 0) {
        M2C_FIELD(arg0, u8 *, 0x92)  = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x78;
        func_020559cc(arg0, 0);
        M2C_FIELD(arg0, s8 *, 0xA2)  = 0;
        M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
        M2C_FIELD(arg0, s8 *, 0x98)  = 0;
        M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x800);
        func_02075738(0, 0x1000);
    }
}
