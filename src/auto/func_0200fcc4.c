#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;

void func_0200fcc4(s32 arg0) {
    M2C_FIELD(&data_0213ad98, u8 *, 3) = (u8) M2C_FIELD(arg0, u8 *, 0xE8);
    M2C_FIELD(&data_0213ad98, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 0xE9);
    M2C_FIELD(&data_0213ad98, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 0xEA);
}
