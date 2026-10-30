/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213be00;

u8 func_020ad87c(void) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        return (u8) ((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x16) >> 0x1E);
    }
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000) {
        if (func_020b39e4(&data_0213be00, 0x70) != 0) {
            return 2U;
        }
        if (func_020b39e4(&data_0213be00, 0x6F) != 0) {
            return 1U;
        }
        goto block_9;
    }
    if (func_020b39e4(&data_0213be00, 0x2A) != 0) {
        return 1U;
    }
block_9:
    return 0U;
}
