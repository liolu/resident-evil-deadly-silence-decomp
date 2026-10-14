#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;

void func_020d9518(void) {
    M2C_FIELD(&data_0213bdcc, s32 *, 0x50) = 0;
    M2C_FIELD(&data_0213ad98, s32 *, 0x10) = 0;
}
