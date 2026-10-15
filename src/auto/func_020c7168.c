/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c7168(void) {
    if (!(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), u8 *, 0xA) & 0x20)) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) != 0) {
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), s8 *, 0xA) = 0x46;
        return;
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x23) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4C) =
        (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4C) | 2);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x1C), s8 *, 0xA) = 0x47;
}
