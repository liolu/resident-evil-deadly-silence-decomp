/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_021007e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0213b890;

void func_020d67a8(void) {
    func_021007e8(0x04000050, 8, 7, 0x10, 0);
    *(s32 *) 0x04000000                   = (*(s32 *) 0x04000000 & ~0x1F00) | 0xF00;
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0x40;
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
}
