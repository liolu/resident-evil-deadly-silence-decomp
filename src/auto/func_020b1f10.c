#include "m2c.h"

extern M2C_UNK data_0214dbec;

s32 func_020b1f10(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = (s32) ((s32 *) &data_0214dbec)[(M2C_FIELD(arg0, u8 *, 2) & 0x3F)];
    return 6;
}
