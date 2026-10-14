/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020c6568(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) - 0x7D0);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x140) = 0x1000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x142) = (s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10);
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) <= 0x64) {
        M2C_FIELD(&data_0213b890, u8 *, 0x22) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x22) + 1);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x1000;
    }
}
