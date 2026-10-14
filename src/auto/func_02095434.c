#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

u8 func_02095434(void) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        return 1U;
    }
    return (u8) ((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x14) >> 0x1E);
}
