/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d4a6c(void) {
    u16 temp_r2;

    temp_r2                                = M2C_FIELD(&data_0213b890, u16 *, 0x26);
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (temp_r2 - 1);
    if (temp_r2 == 0) {
        func_020b5540(1);
        func_020c4798(2);
    }
}
