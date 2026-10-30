/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(u8);                          /* extern */
M2C_UNK func_020b67e8();                            /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020c63e8(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x21)) { /* irregular */
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x32C) = 0xAU;
            M2C_FIELD(&data_0213b890, u8 *, 0x21)                            = 1U;
            return;
        case 1:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x32C) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x32C) - 1);
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x32C) == 0) {
                func_020b67e8();
                func_020b5540((u8) M2C_FIELD(&data_0213b890, s32 *, 0x2C));
                func_020c46b4(0);
            }
            return;
    }
}
