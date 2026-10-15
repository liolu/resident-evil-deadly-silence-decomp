/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

void func_020ba474(void) {
    if (M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80) {
        return;
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x279)                           = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x279) | 2);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) = 0;
}
