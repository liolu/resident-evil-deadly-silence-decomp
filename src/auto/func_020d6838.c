/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02005648();                            /* extern */
s32 func_02005984();                                /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d6838(void) {
    if ((M2C_FIELD(&data_0213b890, u8 *, 0x1F) != 0) || (func_02005984() != 0)) {
        func_02005648();
        func_020c4798(2);
    }
}
