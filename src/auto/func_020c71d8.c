/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c71d8(void) {
    s16 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10);
    if (temp_r1 != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = (s16) (temp_r1 - 1);
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) == 0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x96) = 0x81U;
        }
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x7A) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x96) != 0) {
        return;
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x23)                            = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x70)  = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x8C)  = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x5A;
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4B) == 0) {
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), s8 *, 0xA) = 0x46;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12)                         = 1;
        return;
    }
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), s8 *, 0xA) = 0x48;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12)                         = 2;
}
