#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02144cc0;

void func_02073bcc(void) {
    M2C_FIELD(&data_0213ad98, s16 *, 0x20) = 0;
    M2C_FIELD(&data_02144cc0, s16 *, 0xE0) = 0;
    M2C_FIELD(&data_0213ad98, s16 *, 0x22) = 0;
}
