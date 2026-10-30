/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0209fabc(M2C_UNK);                     /* extern */
M2C_UNK func_020b7db8();                            /* extern */
M2C_UNK func_020b8374();                            /* extern */
extern u16 data_0213ad84;

void func_02096544(void) {
    if (data_0213ad84 == 0) {
        func_020b8374();
        func_020b7db8();
        func_0209fabc(2);
    }
}
