/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d058c(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* irregular */
        case 0:
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xD) == 1) {
                M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0x14U;
                M2C_FIELD(&data_0213b890, u8 *, 0x22)  = 1U;
            }
            return;
        case 1:
            M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
            if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
                func_020c4798(3);
            }
            return;
    }
}
