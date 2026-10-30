/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ac2a4(M2C_UNK);                     /* extern */
extern M2C_UNK data_02147cc0;

void func_020aa44c(void *arg0) {
    u8 temp_r0;

    M2C_FIELD(arg0, s8 *, 0x92) = 0x13;
    M2C_FIELD(arg0, s8 *, 0x93) = 0;
    temp_r0                     = M2C_FIELD(M2C_FIELD(&data_02147cc0, void **, 0x53C), u8 *, 1);
    if ((temp_r0 == 0) && (temp_r0 != 0xFF) && (M2C_FIELD(M2C_FIELD(&data_02147cc0, void **, 0x53C), u8 *, 0) == 5)) {
        func_020ac2a4(0);
    }
}
