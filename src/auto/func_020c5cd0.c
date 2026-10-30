/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c0110(s32);                         /* extern */
M2C_UNK func_020c5b48();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020c5cd0(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 1) {
        func_020c5b48();
        *(s32 *) 0x04001000 = (*(s32 *) 0x04001000 & ~0x1F00) | 0x1800;
        func_020c0110(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x2FC);
        func_020c0110(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x314);
    }
}
