/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b6820(u16);                         /* extern */
extern M2C_UNK data_0213b890;

void func_020d311c(void) {
    u8 temp_r1;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x4E) = 0xA0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x50) = 0x60;
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEA);
    if (temp_r1 != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEA) = (u8) (temp_r1 - 1);
        M2C_FIELD(&data_0213b890, s8 *, 0x21)                           = 0;
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xEF) = 1;
    M2C_FIELD(&data_0213b890, s8 *, 0x21)                           = 4;
    func_020b6820(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2));
}
