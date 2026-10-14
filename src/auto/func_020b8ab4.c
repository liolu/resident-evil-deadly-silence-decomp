/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s8 func_02076b74(M2C_UNK);                          /* extern */
s8 func_02076dc8(M2C_UNK, void *);                  /* extern */

void func_020b8ab4(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
    M2C_FIELD(arg2, s8 *, 0) = func_02076dc8(arg0, arg2);
    M2C_FIELD(arg2, s8 *, 1) = func_02076b74(arg1);
}
