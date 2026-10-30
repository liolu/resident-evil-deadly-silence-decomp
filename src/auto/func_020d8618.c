/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
s32 func_0210e4d8(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0213caa0;
extern M2C_UNK data_02141cc0;
extern M2C_UNK func_020d8488;

s32 func_020d8618(void) {
    if ((u32) (M2C_FIELD(&data_02141cc0, s32 *, 0x40) - 4) <= 2U) {
        return 1;
    }
    if (func_0210e4d8(&func_020d8488) != 2) {
        func_020d87f0();
        return 0;
    }
    M2C_FIELD(&data_0213caa0, s8 *, 0x706) = 0;
    M2C_FIELD(&data_02141cc0, s16 *, 0x50) = 1;
    return 1;
}
