#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_0208e89c(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x836) = 1;
    M2C_FIELD(&data_0213b890, s32 *, 0x74)                           = 0;
    M2C_FIELD(&data_0213b890, s32 *, 0x78)                           = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x54)                            = 0;
}
