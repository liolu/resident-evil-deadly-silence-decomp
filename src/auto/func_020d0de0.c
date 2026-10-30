/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020d0b2c(M2C_UNK);                     /* extern */
s32 func_0211851c(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02143cc0;

void func_020d0de0(void) {
    s32 *temp_r1;
    s32 *temp_r2;
    s32 *temp_r4;
    s32 *temp_r4_2;
    s32 temp_r0;
    s32 temp_r1_2;

    switch (M2C_FIELD(&data_0213b890, u8 *, 0x1C)) {
        default:
            break;
        case 1:
            temp_r4 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
            if ((s32) *temp_r4 < 0x3C000) {
                *temp_r4 = func_0211851c(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xEE) * 0x3C, 0x3E8)
                           << 0xC;
            }
            break;
        case 2:
            temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
            temp_r0 = *temp_r1;
            if (temp_r0 < 0x4E000) {
                *temp_r1 = temp_r0 + 0x1000;
            }
            break;
        case 3:
            temp_r4_2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
            if ((s32) *temp_r4_2 > 0) {
                *temp_r4_2 = func_0211851c(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xEE) * 0x3C, 0x3E8)
                             << 0xC;
            }
            break;
        case 4:
            temp_r2   = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
            temp_r1_2 = *temp_r2;
            if (temp_r1_2 < 0x1E000) {
                *temp_r2 = temp_r1_2 + 0x1000;
            } else {
                M2C_FIELD(&data_0213b890, u8 *, 0x1C) = 0U;
            }
            break;
    }
    if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x41000) {
        M2C_FIELD(&data_02143cc0, s32 *, 0x78) = 0xC8;
        func_020d0b2c(0);
        func_020d0b2c(2);
    }
    if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x4B000) {
        M2C_FIELD(&data_02143cc0, s32 *, 0x78) = 0x96;
        func_020d0b2c(1);
        func_020d0b2c(3);
        func_020b82fc(0xCB);
    }
    if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x4E000) {
        M2C_FIELD(&data_02143cc0, s32 *, 0x78) = 0xC8;
        func_020d0b2c(0);
        func_020d0b2c(2);
        func_020b82fc(0xCA);
    }
}
