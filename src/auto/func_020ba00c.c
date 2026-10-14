/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

void func_020ba00c(void) {
    if (M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80) {
        return;
    }
    if (M2C_FIELD(&data_0213b890, u8 *, 0x278) == 2) {
        M2C_FIELD(&data_0213b890, u8 *, 0x279) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x279) | 0x40);
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x279) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x279) | 2);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0xC) = 0;
}
