#include "m2c.h"

extern M2C_UNK data_0214dbec;

s32 func_020b1ebc(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = (s32) * ((M2C_UNK *) ((s8 *) &data_0214dbec + (M2C_FIELD(arg0, u8 *, 1) * 4)));
    return 0xE;
}
