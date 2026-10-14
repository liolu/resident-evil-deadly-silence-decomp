/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020e7f08(M2C_UNK);

extern s32 data_02153df4;

s32 func_020e7ec4(s32 arg0, s32 arg1) {
    s32 temp_r0;

    if (data_02153df4 == 0) {
        return -1;
    }
    temp_r0 = func_020e7f08(arg0);
    if (temp_r0 == 0) {
        return -3;
    }
    *(M2C_UNK *)arg1 = (s32) M2C_FIELD(temp_r0, s32 *, 0xC);
    return 0;
}
