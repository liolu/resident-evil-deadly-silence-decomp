#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bd00;
extern M2C_UNK data_0213caa0;

s32 func_02094cb0(s32 arg0) {
    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) &&
        (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 0) &&
        ((s32) ((u8 *) &data_0213bd00)[arg0] >= (s32) (M2C_FIELD(&data_0213caa0, u8 *, 0x705) - 1))) {
        return 1;
    }
    return 0;
}
