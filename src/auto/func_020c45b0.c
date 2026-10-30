/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02003560(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020063d0(M2C_UNK);                     /* extern */
M2C_UNK func_020c3c24(M2C_UNK, u8, s32);            /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020c45b0(void) {
    if (data_0213ad84 == 0) {
        *(s32 *) 0x04000000 &= ~0x1F00;
        func_020063d0(0);
        func_02003560(0, 0);
        func_020c3c24(0, M2C_FIELD(&data_0213b890, u8 *, 0x38), M2C_FIELD(&data_0213b890, s32 *, 0x3C));
    }
}
