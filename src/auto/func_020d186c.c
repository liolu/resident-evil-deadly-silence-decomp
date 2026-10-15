#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020d186c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x22) != 0) {
        return;
    }
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
    if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
        M2C_FIELD(&data_0213b890, s8 *, 0x21) = 2;
    }
}
