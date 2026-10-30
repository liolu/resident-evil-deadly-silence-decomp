/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02029ebc();                      /* extern */
M2C_UNK func_020559cc();             /* extern */
M2C_UNK func_020b8110();            /* extern */
s16 func_0211851c();                        /* extern */

void func_0202aa48(void *arg0) {
    u16 temp_r5;

    func_020559cc(arg0, 7);
    func_02029ebc(arg0);
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) (M2C_FIELD(arg0, s16 *, 0x46) - 0x19);
    if ((u32) M2C_FIELD(arg0, u8 *, 0xA2) > 8U) {
        temp_r5                       = M2C_FIELD(arg0, u16 *, 0x188);
        M2C_FIELD(arg0, s16 *, 0x186) = func_0211851c((func_0211851c(temp_r5, 0x64U) + 0xC8) * 0xA28, temp_r5);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x186) > 0xC8) {
            M2C_FIELD(arg0, s16 *, 0x186) = 0xC8;
        }
        M2C_FIELD(arg0, s16 *, 0xA6) = (s16) (func_0211851c(M2C_FIELD(arg0, u16 *, 0x188), 0x64U) + 0xC8);
        M2C_FIELD(arg0, s16 *, 0x46) = -0x100;
        M2C_FIELD(arg0, s8 *, 0x90)  = 1;
        M2C_FIELD(arg0, s8 *, 0x91)  = 1;
        M2C_FIELD(arg0, s8 *, 0x92)  = 6;
        M2C_FIELD(arg0, s8 *, 0x93)  = 0;
        func_020b8110(0x5C);
        func_020b8110(0x5A, 0);
    }
}
