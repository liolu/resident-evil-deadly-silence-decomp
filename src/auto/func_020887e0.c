#include "m2c.h"

extern M2C_UNK data_021375ac;

void func_020887e0(u8 *arg0, u8 *arg1, u8 *arg2) {
    *arg0 = M2C_FIELD(&data_021375ac, u8 *, 0x29);
    *arg1 = M2C_FIELD(&data_021375ac, u8 *, 0x2A);
    *arg2 = M2C_FIELD(&data_021375ac, u8 *, 0x2B);
}
