/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020555b4(void *);                      /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020914e4(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020b8110(M2C_UNK, M2C_UNK);            /* extern */

void func_02040454(void *arg0) {
    u8 temp_r0;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            if (M2C_FIELD(arg0, u8 *, 0xA2) == 0) {
                func_020b8110(0x73, 0);
            }
            M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
            if (((s32) M2C_FIELD(arg0, s16 *, 0xA8) < 0) && (M2C_FIELD(arg0, u8 *, 0xA2) == 8)) {
                M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
                func_020559cc(arg0, 5);
                M2C_FIELD(arg0, u8 *, 0xA2)  = 0U;
                M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
                M2C_FIELD(arg0, s8 *, 0x98)  = 3;
                M2C_FIELD(arg0, s16 *, 0xA8) = 0x46;
            }
            break;
        case 1:
            M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
            M2C_FIELD(arg0, u8 *, 0x93) = 0U;
            func_020559cc(arg0, 5);
            M2C_FIELD(arg0, u8 *, 0xA2) = 0U;
            M2C_FIELD(arg0, s8 *, 0xA3) = 0;
            M2C_FIELD(arg0, s8 *, 0x98) = 3;
            func_020555b4(arg0);
            func_020914e4(arg0 + 0x54, -0x64, -0x64);
            func_020b8110(0x74, 0);
            M2C_FIELD(arg0, u8 *, 8)     = (u8) (M2C_FIELD(arg0, u8 *, 8) | 2);
            M2C_FIELD(arg0, s16 *, 0xA8) = 0x5A;
            break;
    }
    func_02075738(1, 0x400);
    temp_r0 = M2C_FIELD(arg0, u8 *, 0xA2);
    if ((temp_r0 == 0xA) || (temp_r0 == 0x11)) {
        func_020b8110(0x73, 0);
    }
}
