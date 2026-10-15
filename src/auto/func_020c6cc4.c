/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c6cc4(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xA9) != 0) {
        if (M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x1C), u8 *, 0xA) & 0x20) {
            M2C_FIELD(&data_0213b890, s32 *, 0x20) = 0x201;
        }
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x24) == 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x23) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
    }
}
