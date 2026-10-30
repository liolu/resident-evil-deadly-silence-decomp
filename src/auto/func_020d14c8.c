/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d0ad0();                            /* extern */
M2C_UNK func_020d1614(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d14c8(void) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x45);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x45) = 1U;
            M2C_FIELD(&data_0213b890, s8 *, 0x1C)                           = 1;
            return;
        case 1:
            if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 1) {
                if (M2C_FIELD(&data_0213b890, u8 *, 0x1D) != 0) {
                    M2C_FIELD(&data_0213b890, u8 *, 0x1D) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1D) - 1);
                    return;
                }
                M2C_FIELD(&data_0213b890, s8 *, 0x1C) = 1;
                func_020d0ad0();
                if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xEE) == 0x3E8) {
                    func_020d1614(2);
                    return;
                }
            } else {
                func_020d1614(3);
                return;
            }
            break;
    }
}
