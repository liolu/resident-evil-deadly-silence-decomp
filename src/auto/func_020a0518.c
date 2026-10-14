/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02077000(s32, M2C_UNK, s16);               /* extern */
s32 func_02077414(M2C_UNK);                         /* extern */

void func_020a0518(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s16 arg3) {
    M2C_FIELD(arg0, s32 *, 0) = func_02077000(func_02077414(arg1), arg2, arg3);
    M2C_FIELD(arg0, s16 *, 4) = arg3;
}
