/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210469c(u16 *, M2C_UNK);              /* extern */
s32 func_0210d918();                                /* extern */
extern void *data_0215b1ac;

s32 func_0210d8bc(void) {
    s32 temp_r0;

    temp_r0 = func_0210d918();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210469c(M2C_FIELD(data_0215b1ac, u16 **, 4), 2);
    if ((u32) *M2C_FIELD(data_0215b1ac, u16 **, 4) <= 1U) {
        return 3;
    }
    return 0;
}
