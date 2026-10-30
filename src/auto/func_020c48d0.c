/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020c48d0(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0x1F) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1F) - 1);
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 0) {
        if (M2C_FIELD(&data_0213b890, u16 *, 0x26) != 0x1FF) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
            return;
        }
        M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0x1E;
        func_020b82fc(0xD5);
        func_020c4798(2);
    }
}
