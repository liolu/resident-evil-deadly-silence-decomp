/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c4b2c(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0x24)  = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x24) - 1);
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) ^ -1);
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) != 0) {
        return;
    }
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0x1FFU;
    M2C_FIELD(&data_0213b890, u8 *, 0x24)  = 8U;
    M2C_FIELD(&data_0213b890, s8 *, 0x21)  = 1;
}
