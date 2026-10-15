#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213bb18;

void func_02095900(void) {
    if (M2C_FIELD(&data_0213bb18, u8 *, 0x101) == 0) {
        M2C_FIELD(&data_0213bb18, u8 *, 0x101) = 1U;
    }
}
