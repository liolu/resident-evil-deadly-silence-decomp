/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02107d18(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0210d458();                            /* extern */
s32 func_0210d814(M2C_UNK, M2C_UNK);                /* extern */
s32 func_0210d918();                                /* extern */
extern s16 data_0215b1a8;
extern s32 data_0215b1ac;

s32 func_0210dab0(void) {
    s32 temp_r0;

    if (func_0210d918() != 0) {
        return 3;
    }
    temp_r0 = func_0210d814(1, 0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210d458();
    func_02107d18(0xA, 0);
    data_0215b1ac = 0;
    data_0215b1a8 = 0;
    return 0;
}
