/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d6c34();                            /* extern */
M2C_UNK func_020d87f0(u16);                         /* extern */
extern M2C_UNK data_02126cb4;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *);

void func_020d6acc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        if (data_0213ad20 != NULL) {
            data_0213ad20(&data_02126cb4);
        }
        func_020d87f0(M2C_FIELD(arg0, u16 *, 2));
        func_020d6c34();
    }
}
