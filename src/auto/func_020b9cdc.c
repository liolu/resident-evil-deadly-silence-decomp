#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213acfc;

void func_020b9cdc(void) {
    M2C_FIELD(&data_0213acfc, s8 *, 0x1F)  = 0;
    M2C_FIELD(&data_0213acfc, s8 *, 0x20)  = 0;
    M2C_FIELD(&data_0213acfc, s16 *, 0x18) = 0;
    M2C_FIELD(&data_0213acfc, s8 *, 0x1A)  = 0;
}
