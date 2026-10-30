/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0207260c(void *);                      /* extern */
extern M2C_UNK data_0211d9e0;
extern u8 data_0213ad84;

void func_02072850(void *arg0) {
    if (data_0213ad84 == 0) {
        func_020038b8(&data_0211d9e0);
        func_0207260c(arg0);
        func_0206fcf8(0, 2, 0, 0x100);
        M2C_FIELD(arg0, s8 *, 1) = 2;
    }
}
