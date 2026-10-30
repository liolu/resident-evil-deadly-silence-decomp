/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b80f4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020cfa88(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x21)) { /* irregular */
        case 0:
            M2C_FIELD(&data_0213b890, u16 *, 0x26) = 0xAU;
            M2C_FIELD(&data_0213b890, u8 *, 0x21)  = 1U;
            return;
        case 1:
            M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
            if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
                func_020b80f4(6, -1);
                func_020c46b4(0);
            }
            return;
    }
}
