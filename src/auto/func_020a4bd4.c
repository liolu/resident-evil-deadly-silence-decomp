/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020a4bd4(void) {
    if (data_0213ad84 != 0) {
        return;
    }
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0x20;
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 2) = 0;
}
