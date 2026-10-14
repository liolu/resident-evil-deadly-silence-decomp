#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020d1614(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x44) = (s8) arg0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x45) = 0;
}
