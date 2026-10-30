/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d6c34();                            /* extern */
extern M2C_UNK data_0213caa0;

void func_020d914c(void) {
    if ((M2C_FIELD(&data_0213caa0, u8 *, 0x55E) != 0) && (M2C_FIELD(&data_0213caa0, u8 *, 0x700) != 4)) {
        M2C_FIELD(&data_0213caa0, u8 *, 0x700) = 4U;
        M2C_FIELD(&data_0213caa0, s8 *, 0x701) = 0;
        M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 0;
        func_020d6c34();
        M2C_FIELD(&data_0213caa0, s8 *, 0x709) = 0;
    }
}
