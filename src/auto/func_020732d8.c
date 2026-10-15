#include "m2c.h"

extern u8 data_0213ad84;
extern M2C_UNK data_0213bdcc;

void func_020732d8(void *arg0) {
    if (data_0213ad84 != 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 1)               = 2;
    M2C_FIELD(arg0, s16 *, 0x10)           = 0x14;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x40000);
}
