#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021374cc;

void func_02085de8(void) {
    if ((u32) M2C_FIELD(&data_021374cc, u16 *, 0x20) > 0x3E7U) {
        M2C_FIELD(&data_021374cc, u16 *, 0x20) = 0x3E7U;
    }
    if ((u32) M2C_FIELD(&data_021374cc, u16 *, 0x16) < (u32) M2C_FIELD(&data_021374cc, u16 *, 0x20)) {
        M2C_FIELD(&data_021374cc, u16 *, 0x16) = (u16) M2C_FIELD(&data_021374cc, u16 *, 0x20);
    }
}
