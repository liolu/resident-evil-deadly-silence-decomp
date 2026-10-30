/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8310(u8);                          /* extern */
s32 func_0211851c(s16, M2C_UNK);                    /* extern */
extern M2C_UNK data_0211bc32;
extern void *data_0213ad2c;

void func_020128cc(void *arg0, void *arg1) {
    u32 temp_r0_2;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_0213ad2c, u8 *, 8);
    if ((u32) temp_r0 > 5U) {
        temp_r0_2 = temp_r0 - 6;
        switch (temp_r0_2) {
            default:
                break;
            case 0:
            case 1:
                M2C_FIELD(arg1, s32 *, 8) =
                    (s32) (M2C_FIELD(arg1, s32 *, 8) - func_0211851c(M2C_FIELD(arg1, s16 *, 0x14), 0x64));
                break;
            case 2:
            case 3:
                M2C_FIELD(arg1, s32 *, 8) =
                    (s32) (M2C_FIELD(arg1, s32 *, 8) + func_0211851c(M2C_FIELD(arg1, s16 *, 0x14), 0x64));
                break;
        }
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x14) {
        func_0206fcf8(0, 1, 1, 0x100);
    }
    M2C_FIELD(arg1, s16 *, 0xE)  = (s16) (M2C_FIELD(arg1, s16 *, 0xE) - 0xA0);
    M2C_FIELD(arg1, s32 *, 0)    = (s32) (M2C_FIELD(arg1, s32 *, 0) + func_0211851c(M2C_FIELD(arg1, s16 *, 0x12), 0x64));
    M2C_FIELD(arg1, s16 *, 0x12) = (s16) (M2C_FIELD(arg1, s16 *, 0x12) + 0xF);
    M2C_FIELD(arg1, s16 *, 0x14) = (s16) (M2C_FIELD(arg1, s16 *, 0x14) - 8);
    if ((s32) M2C_FIELD(arg1, s16 *, 0x14) < 0) {
        M2C_FIELD(arg1, s16 *, 0x14) = 0;
    }
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0) {
        M2C_FIELD(arg0, s8 *, 4) = 2;
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc32 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
}
