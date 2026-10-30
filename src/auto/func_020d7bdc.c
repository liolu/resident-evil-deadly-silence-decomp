/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d7b28();                                /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02126e98;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *);

void func_020d7bdc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d880c(9);
        return;
    }
    if (func_020d7b28() == 0) {
        if (data_0213ad20 != NULL) {
            data_0213ad20(&data_02126e98);
        }
        func_020d880c(9);
    }
}
