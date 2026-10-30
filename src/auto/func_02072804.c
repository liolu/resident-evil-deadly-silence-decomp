/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_020726e8();                                /* extern */
extern u8 data_0213ad84;

void func_02072804(void *arg0) {
    if ((data_0213ad84 == 0) && (func_020726e8() != 0)) {
        M2C_FIELD(arg0, s8 *, 1) = 3;
        func_0206fcf8(0, 1, 1, 0x80);
    }
}
