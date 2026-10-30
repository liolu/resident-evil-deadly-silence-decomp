/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020956d8(M2C_UNK);                     /* extern */
M2C_UNK func_0209572c();                            /* extern */
extern M2C_UNK data_0213ad48;

void func_02095764(void) {
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        func_020956d8(0x64);
        func_0209572c();
    }
}
