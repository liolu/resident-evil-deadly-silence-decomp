#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021374cc;

void func_02085e1c(void) {
    if ((u32) M2C_FIELD(&data_021374cc, u16 *, 0x22) > 0x3E7U) {
        M2C_FIELD(&data_021374cc, u16 *, 0x22) = 0x3E7U;
    }
    if ((u32) M2C_FIELD(&data_021374cc, u16 *, 0x1A) < (u32) M2C_FIELD(&data_021374cc, u16 *, 0x22)) {
        M2C_FIELD(&data_021374cc, u16 *, 0x1A) = (u16) M2C_FIELD(&data_021374cc, u16 *, 0x22);
    }
}
