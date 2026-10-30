/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020cb9a4(void) {
    u16 temp_r2;
    u8 temp_r1;

    temp_r2                                = M2C_FIELD(&data_0213b890, u16 *, 0x26);
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (temp_r2 - 1);
    if (temp_r2 == 0) {
        temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x2C);
        if (temp_r1 != 0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x2C) = (u8) (temp_r1 - 1);
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x2C) != 0) {
                M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0x1EU;
            } else {
                M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0x3CU;
            }
            func_020b82fc(0xD);
            return;
        }
        func_020c4798(2);
    }
}
