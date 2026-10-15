#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

void func_02094c10(void) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        M2C_FIELD(&data_0213bb18, s8 *, 0x21C) = 0xA;
    }
}
