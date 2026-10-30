/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad30;
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020d513c(void) {
    if (data_0213ad84 == 0) {
        if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 2) {
            func_020c4798(2);
        }
        M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
        if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
            func_020c4798(2);
        }
    }
}
