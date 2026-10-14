/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020f3244(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_021061d8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b3ac;

s32 func_02077f6c(M2C_UNK arg0) {
    s32 temp_r0;

    temp_r0 = func_020f3244(&data_0213b3ac, arg0);
    M2C_FIELD(&data_0213b2b4, s32 *, 0xB8) = temp_r0;
    if (temp_r0 != 0) {
        func_021061d8(temp_r0, 0, arg0);
    }
    return temp_r0;
}
