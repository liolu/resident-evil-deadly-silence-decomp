/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213bdcc;
extern void *data_0213daa8;

s32 func_020b4c68(void) {
    void *temp_r2;

    temp_r2 = data_0213daa8;
    data_0213daa8 = temp_r2 + 2;
    if (M2C_FIELD(temp_r2, u8 *, 1) == 0) {
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x100000);
    } else {
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x100000);
    }
    return 1;
}
