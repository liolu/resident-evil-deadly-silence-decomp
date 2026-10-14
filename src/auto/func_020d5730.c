#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020d5730(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0x90) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x90) & ~2);
}
