/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b4c1c();                            /* extern */
extern M2C_UNK data_0213bdcc;

s32 func_020b4394(void) {
    s32 temp_r2;

    func_020b4c1c();
    temp_r2 = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x400;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_r2;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (temp_r2 & ~0x800);
    return 0;
}
