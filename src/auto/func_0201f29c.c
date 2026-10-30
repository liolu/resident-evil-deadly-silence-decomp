/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd504(s16);                         /* extern */
M2C_UNK func_0201ea80(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020555b4(void *);                      /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020914e4(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_0201f29c(void *arg0) {
    func_01ffd504(M2C_FIELD(arg0, s16 *, 0x180));
    func_0201ea80(arg0, 0xA, 0);
    if (func_02075738(0, 0x400) != 0) {
        M2C_FIELD(arg0, s8 *, 0x91)  = 3;
        M2C_FIELD(arg0, u8 *, 8)     = (u8) (M2C_FIELD(arg0, u8 *, 8) | 0xA);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0x46;
        func_020555b4(arg0);
        func_020914e4(arg0 + 0x54, -0x5A, -0x5A);
    }
}
