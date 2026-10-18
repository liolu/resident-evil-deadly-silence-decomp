#include "m2c.h"

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bdc6;
extern M2C_UNK data_0213caa0;

u8 func_0209533c(void) {
    u8 var_r0;

    if (M2C_FIELD(&data_0213bb18, u8 *, 0x236) != 0xFF) {
        if ((M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) ||
            (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 0)) {
            return 1U;
        }
        if (M2C_FIELD(&data_0213bb18, u8 *, 0x236) == ((u8 *) &data_0213bdc6)[M2C_FIELD(&data_0213caa0, u8 *, 0x706)]) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 2U;
}
