/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f4914(s32);                         /* extern */
extern M2C_UNK data_021543a4;
extern M2C_UNK data_02154504;

M2C_UNK *func_020f488c(void) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(&data_021543a4, s32 *, 0xFC) & 0x80;
    if (temp_r0 == 0) {
        func_020f4914(temp_r0);
        M2C_FIELD(&data_021543a4, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_021543a4, s32 *, 0xFC) | 0x80);
    }
    return &data_02154504;
}
