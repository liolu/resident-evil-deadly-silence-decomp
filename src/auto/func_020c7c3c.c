/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020c7c3c(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x5E) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xB2) != 0) {
        return;
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x23) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xC4) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE8) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xEE) = 0;
}
