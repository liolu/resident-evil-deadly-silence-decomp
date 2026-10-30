/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d6bdc();                                /* extern */
M2C_UNK func_020d6d4c();                            /* extern */
extern M2C_UNK data_0213caa0;
extern M2C_UNK data_0213d1a0;

void func_020d8918(void) {
    if ((M2C_FIELD(&data_0213caa0, u8 *, 0x55E) != 0) && (M2C_FIELD(&data_0213caa0, u8 *, 0x55F) == 1)) {
        if (func_020d6bdc() == 0) {
            func_020d6d4c();
            return;
        }
        M2C_FIELD(&data_0213caa0, s32 *, 0x554) = 0;
        M2C_FIELD(&data_0213caa0, s8 *, 0x701)  = 1;
        M2C_FIELD(&data_0213caa0, u8 *, 0x55E)  = 0U;
        M2C_FIELD(&data_0213d1a0, s16 *, 0x18)  = 0;
        M2C_FIELD(&data_0213caa0, s8 *, 0x705)  = 0;
    }
}
