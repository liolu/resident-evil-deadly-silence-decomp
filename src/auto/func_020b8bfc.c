/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020059ac();                            /* extern */
s32 func_02005be4();                                /* extern */
M2C_UNK func_02005c34();                            /* extern */
M2C_UNK func_020c3b9c(M2C_UNK *);                   /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213b8e0;

void func_020b8bfc(void) {
    func_02005c34();
    if ((func_02005be4() == 0) && (data_0213ad84 == 0)) {
        func_020059ac();
        func_020c3b9c(&data_0213b8e0);
        func_020c46b4(0);
    }
}
