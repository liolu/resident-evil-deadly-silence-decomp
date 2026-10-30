/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d80c0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_02127024;
extern M2C_UNK data_0213caa0;
extern M2C_UNK func_020d8c28;

void func_020d8bd4(void) {
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x55F) == 1) {
        func_020d80c0(&func_020d8c28, &data_02127024, 0);
        M2C_FIELD(&data_0213caa0, s32 *, 0x554) = 0;
        M2C_FIELD(&data_0213caa0, s8 *, 0x701)  = 1;
    }
}
