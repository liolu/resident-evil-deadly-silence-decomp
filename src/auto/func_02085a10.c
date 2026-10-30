/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020858ec(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s16 func_02103720(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213b1b4;

s32 func_02085a10(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_FIELD(arg0, s16 *, 4) = func_02103720(&data_0213b1b4, arg2);
    if (M2C_FIELD(arg0, s16 *, 4) == 0) {
        return 0;
    }
    return func_020858ec(arg0, arg1, arg2, arg3);
}
