/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020d5388(void) {
    if ((s32) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2) + 1) < (s32) M2C_FIELD((M2C_FIELD(&data_0213b890, void **, 0x4C) + M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 1)), u8 *, 0x18)) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 5) = 1;
    } else {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 5) = 0;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2) != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 4) = 1;
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 4) = 0;
}
