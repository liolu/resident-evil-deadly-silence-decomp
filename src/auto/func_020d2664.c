/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b3a00(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213be20;

void func_020d2664(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* irregular */
        case 0:
            M2C_FIELD(&data_0213b890, u8 *, 0x22)                           = 1U;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE4) = 1;
            func_020b3a00(&data_0213be20, 0xB);
            return;
        case 1:
            if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE5) >= 0x28U) {
                func_020b5540(1);
                func_020c4798(3);
            }
            return;
    }
}
