#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213bdcc;

void func_02070f98(void) {
    if (M2C_FIELD(&data_0213bdcc, u8 *, 0x2B6) != 0) {
        M2C_FIELD(&data_0213bdcc, u8 *, 0x2B6) = 0U;
    }
}
