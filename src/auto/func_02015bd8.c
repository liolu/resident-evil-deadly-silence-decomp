/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201697c(s8 *);                        /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213be18;

void func_02015bd8(s8 *arg0) {
    if (func_020b39e4(&data_0213be18, 0) != 0) {
        *arg0 = 1;
        func_0201697c(arg0);
    }
}
