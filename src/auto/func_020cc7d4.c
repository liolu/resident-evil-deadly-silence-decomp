/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020cc7d4(void) {
    M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
    if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
        M2C_FIELD(&data_0213b890, u16 *, 0x26) = 1U;
        func_020c4798(2);
    }
}
