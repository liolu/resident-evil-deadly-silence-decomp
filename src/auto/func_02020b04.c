/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201ea18(void *, s16);                 /* extern */
M2C_UNK func_0201eaa4(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */

void func_02020b04(void *arg0) {
    s16 temp_r2;

    if (M2C_FIELD(arg0, s16 *, 0x18E) != 0) {
        func_0201eaa4(arg0, 0x32, 0x82);
    }
    if (!(M2C_FIELD(arg0, u16 *, 0x188) & 0x11)) {
        M2C_FIELD(arg0, s8 *, 0x91)   = 0;
        M2C_FIELD(arg0, s8 *, 0xA)    = 4;
        M2C_FIELD(arg0, u16 *, 0x198) = (u16) (M2C_FIELD(arg0, u16 *, 0x198) & ~0x80);
        if (!(M2C_FIELD(arg0, u16 *, 0x196) & 1)) {
            M2C_FIELD(arg0, s16 *, 0x190) = 0x28;
        }
        goto block_8;
    }
    temp_r2                       = M2C_FIELD(arg0, s16 *, 0x18C);
    M2C_FIELD(arg0, s16 *, 0x18C) = (s16) (temp_r2 + 1);
    if ((s32) temp_r2 >= 8) {
        M2C_FIELD(arg0, u8 *, 0x92)  = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, s16 *, 0xA6) = -0x82;
        func_020559cc(arg0, 0xA);
        M2C_FIELD(arg0, s8 *, 0xA2)   = 0;
        M2C_FIELD(arg0, s8 *, 0xA3)   = 0;
        M2C_FIELD(arg0, s16 *, 0x18C) = 0;
        return;
    }
block_8:
    func_0201ea18(arg0, M2C_FIELD(arg0, s16 *, 0x182));
}
