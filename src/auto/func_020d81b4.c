/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d6d4c();                            /* extern */
s32 func_020d8180();                                /* extern */
M2C_UNK func_020d87f0();                            /* extern */
extern M2C_UNK data_02126f7c;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *);

void func_020d81b4(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d6d4c();
        return;
    }
    if (func_020d8180() == 0) {
        if (data_0213ad20 != NULL) {
            data_0213ad20(&data_02126f7c);
        }
        func_020d6d4c();
    }
}
