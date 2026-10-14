#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021374cc;

void func_02085f2c(void) {
    M2C_FIELD(&data_021374cc, u16 *, 0x10) = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0x10) + 1);
}
