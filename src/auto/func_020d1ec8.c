/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc();                         /* extern */
extern M2C_UNK data_0213b890;

void func_020d1ec8(void) {
    u16 temp_r0;
    u16 temp_r1;
    u8 temp_r0_2;
    u8 var_r3;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF0);
    switch (temp_r0) {                              /* irregular */
        case 0xD0:
            var_r3 = 0xD;
            break;
        case 0xD7:
            var_r3 = 0xB;
            break;
        default:
            var_r3 = 0xFF;
            break;
    }
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2);
    if (temp_r0 != temp_r1) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEE) = var_r3;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) =
            (u16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF0);
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) != 0) {
            func_020b82fc();
        }
    } else {
        temp_r0_2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEE);
        if (temp_r0_2 != 0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEE) = (u8) (temp_r0_2 - 1);
            return;
        }
        if (temp_r1 != 0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEE) = var_r3;
            func_020b82fc(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2));
        }
    }
}
