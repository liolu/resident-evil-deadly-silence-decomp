/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020293cc();                            /* extern */

void func_0202954c(void *arg0) {
    u8 temp_r1;

    if (!(M2C_FIELD(arg0, u8 *, 0xA) & 0x80)) {
        temp_r1 = M2C_FIELD(arg0, u8 *, 0x92);
        switch (temp_r1) {
            default:
                break;
            case 0:
            case 2:
                func_020293cc(arg0);
                break;
            case 1:
                M2C_FIELD(arg0, s8 *, 0x90) = 0;
                M2C_FIELD(arg0, s8 *, 0x91) = 0;
                M2C_FIELD(arg0, u8 *, 0x92) = 0U;
                M2C_FIELD(arg0, s8 *, 0x93) = 0;
                M2C_FIELD(arg0, u8 *, 0xA)  = 0x11U;
                break;
            case 3:
                M2C_FIELD(arg0, s8 *, 0x90) = 0;
                M2C_FIELD(arg0, s8 *, 0x91) = 0;
                M2C_FIELD(arg0, u8 *, 0x92) = 0U;
                M2C_FIELD(arg0, s8 *, 0x93) = 0;
                M2C_FIELD(arg0, u8 *, 0xA)  = 0x10U;
                break;
        }
        M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) & 0x1F);
    }
}
