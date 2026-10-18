#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bd00;
extern M2C_UNK data_0213caa0;

void func_02094d0c(u8 arg0) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        return;
    }
    if (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) != 0) {
        return;
    }
    ((u8 *) &data_0213bd00)[arg0] = ((u8 *) &data_0213bd00)[arg0] + 1;
    if (M2C_FIELD(&data_0213bb18, u8 *, 0x237) == 0xFF) {
        M2C_FIELD(&data_0213bb18, u8 *, 0x237) = arg0;
        return;
    }
    M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 1;
}
