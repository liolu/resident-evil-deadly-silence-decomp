/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020c4a5c(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0x24) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x24) + 1);
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x24)) { /* irregular */
        case 15:
            func_020b82fc(0x6A);
            return;
        case 30:
            func_020b5540(1);
            func_020c4798(3);
            return;
    }
}
