/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02126550;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;

void func_020d210c(void) {
    u16 temp_r3;

    temp_r3 = ((s16 *) &data_02126550)[M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2)];
    M2C_FIELD(&data_0213ba90, u16 *, 0x24)                          = temp_r3;
    M2C_FIELD(&data_0213ba90, u16 *, 0x34)                          = temp_r3;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE3) = 0x24;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2) =
        (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2) + 1);
    if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2) > 0x24U) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2) = 0U;
    }
}
