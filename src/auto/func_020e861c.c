/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e86b8(s8 *, s8 **, M2C_UNK);            /* extern */
s32 func_020e8714(s8 *, s8 **, M2C_UNK);            /* extern */
M2C_UNK func_020e8720(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_02110440(M2C_UNK *, M2C_UNK *, s8 *, M2C_UNK); /* extern */
u32 func_0211282c();                                /* extern */
extern M2C_UNK data_0213136c;
extern M2C_UNK data_02153ee0;

s32 func_020e861c(s8 *arg0, s32 *arg1) {
    s8 *sp0;
    s32 temp_r4;

    if (func_0211282c() >= 0x12U) {
        func_02110440(&data_02153ee0, &data_0213136c, arg0, 0x12);
        func_020e8720(0, &data_02153ee0);
    }
    sp0 = arg0;
    temp_r4 = func_020e86b8(arg0, &sp0, 0x10);
    if (*sp0 != 0) {
        sp0 += 1;
    }
    if (arg1 != NULL) {
        *arg1 = func_020e8714(sp0, &sp0, 0x10);
    }
    return temp_r4;
}
