/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c7930(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x24) != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x36) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x36) + 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x36) == 2) {
        M2C_FIELD(&data_0213b890, u8 *, 0x23) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x24) = 1U;
}
