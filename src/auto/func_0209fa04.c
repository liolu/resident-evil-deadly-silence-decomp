/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b7c6c(M2C_UNK);                         /* extern */
M2C_UNK func_020b8374();                            /* extern */
M2C_UNK func_020b84ec();                            /* extern */
M2C_UNK func_020d914c();                            /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK func_020d69c0;

void func_0209fa04(void) {
    if ((data_0213ad84 == 0) && (func_020b7c6c(0) == 0)) {
        M2C_FIELD(&data_0213af7c, s8 *, 0x20) = 0;
        func_020b84ec();
        func_020b8374();
        func_020d914c();
        M2C_FIELD(&data_0213b2b4, M2C_UNK **, 0xA8) = &func_020d69c0;
    }
}
