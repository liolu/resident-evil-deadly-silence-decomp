/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0209fabc(M2C_UNK);                     /* extern */
M2C_UNK func_020d8e34(u8);                          /* extern */
M2C_UNK func_020d8e9c(u32);                         /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213caa0;

void func_0209657c(void) {
    u32 temp_r0;

    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) =
        (u8) ((M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) & ~1) | 1);
    if ((data_0213ad84 == 0) && (M2C_FIELD(&data_0213caa0, u8 *, 0x702) == 0)) {
        temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) << 0x1A) >> 0x1F;
        if (temp_r0 != 0) {
            func_020d8e9c(temp_r0);
        } else {
            func_020d8e34(M2C_FIELD(&data_0213caa0, u8 *, 0x708));
        }
        func_0209fabc(1);
    }
}
