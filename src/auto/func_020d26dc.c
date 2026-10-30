/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d26dc(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* irregular */
        case 0:
            func_020b82fc(0x76);
            M2C_FIELD(&data_0213b890, u8 *, 0x22) = 1U;
            return;
        case 1:
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE3) ==
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE2)) {
                M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0;
                M2C_FIELD(&data_0213b890, s8 *, 0x21) = 2;
                M2C_FIELD(&data_0213b890, u8 *, 0x22) = 0U;
            }
            return;
    }
}
