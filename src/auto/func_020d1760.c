/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b736c();                                /* extern */
M2C_UNK func_020d0964();                            /* extern */
M2C_UNK func_020d0f74();                            /* extern */
u8 func_02118728(s32, M2C_UNK);                     /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020d1760(void) {
    if ((data_0213ad84 == 0) &&
        (func_020d0f74(), func_020d0964(),
         M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEC) = func_02118728(func_020b736c() * 0xB, 0x7F),
         ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xEC) > 1U))) {
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x40) != 4) {
            M2C_FIELD(&data_0213b890, s8 *, 0x1F) = 1;
            return;
        }
        M2C_FIELD(&data_0213b890, s8 *, 0x1F) = 0;
    }
}
