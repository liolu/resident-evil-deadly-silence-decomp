#include "m2c.h"
#include "engine.h"

extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020c0fb0(void) {
    if (data_0213ad84 == 0) {
        M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
    }
}
