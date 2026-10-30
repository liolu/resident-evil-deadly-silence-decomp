/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_021007e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern u8 data_0213ad84;

void func_02077700(void *arg0) {
    if (data_0213ad84 == 0) {
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) - 1);
        if (M2C_FIELD(arg0, u16 *, 6) == 0) {
            func_021007e8(0x04000050, 4, 8, 0x10, 0);
            *(s32 *) 0x04000000      = (*(s32 *) 0x04000000 & ~0x1F00) | 0xC00;
            M2C_FIELD(arg0, s8 *, 2) = 2;
        }
    }
}
