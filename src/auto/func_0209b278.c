/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02098030();                            /* extern */
s32 func_020b7c6c(M2C_UNK);                         /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213af7c;

void func_0209b278(void) {
    if ((data_0213ad84 == 0) && (func_020b7c6c(0) == 0)) {
        M2C_FIELD(&data_0213af7c, s8 *, 0x20) = 0;
        func_02098030();
        func_020c4798(4);
    }
}
