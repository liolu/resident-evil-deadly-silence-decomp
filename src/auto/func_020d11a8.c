/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d0cbc(M2C_UNK);                     /* extern */
M2C_UNK func_020d135c(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d11a8(void) {
    s32 *temp_r2;
    s32 *temp_r2_2;
    s32 temp_r1;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x42);
    switch (temp_r0) {                              /* irregular */
        case 0:
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x40) != 2) {
                func_020d0cbc(2);
                M2C_FIELD(&data_0213b890, s8 *, 0x1D) = 0xF;
            }
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x40) = 2U;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x42) = 1U;
            return;
        case 1:
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xEE) == 0x3E8) {
                func_020d135c(4);
            }
            temp_r2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20), s32 **, 0x10);
            temp_r1 = *temp_r2;
            if ((temp_r1 == 0x1E000) && (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 1)) {
                *temp_r2 = temp_r1 - 0x1000;
            }
            temp_r2_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20), s32 **, 0x10);
            if (*temp_r2_2 == 0x46000) {
                if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 1) {
                    *temp_r2_2 = 0;
                    return;
                }
                func_020d135c(0);
            } else {
                return;
            }
            break;
    }
}
