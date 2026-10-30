/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020cdc14(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* irregular */
        case 0:
            M2C_FIELD(&data_0213b890, u8 *, 0x1F) = 0x14U;
            M2C_FIELD(&data_0213b890, u8 *, 0x22) = 1U;
            return;
        case 1:
            M2C_FIELD(&data_0213b890, u8 *, 0x1F) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1F) - 1);
            if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 0) {
                func_020b5540(1);
                func_020b82fc(0xBB);
                func_020c4798(3);
            }
            return;
    }
}
