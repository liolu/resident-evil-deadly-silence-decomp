/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e92ac(s32, void *, void *, void *, void *); /* extern */
M2C_UNK func_020e956c(s32, void *, void *);         /* extern */
M2C_UNK func_020e967c(void *, void *);              /* extern */
s32 func_020e9758(s32, void *);                     /* extern */
s32 func_020ec834();                                /* extern */
s32 func_020ec9d0(s32, M2C_UNK);                    /* extern */

s32 func_020e99ac(void *arg0) {
    s32 temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x1AC) == 0) {
        return -1;
    }
    temp_r0 = func_020ec834();
    if (temp_r0 == -1) {
        return -1;
    }
    if (temp_r0 != 1) {
        return 1;
    }
    if (func_020ec9d0(M2C_FIELD(arg0, s32 *, 0x1AC), 0x14) == 0) {
        return -1;
    }
    if (func_020e9758(M2C_FIELD(arg0, s32 *, 0x1AC), arg0 + 0x1B4) < 0) {
        return -1;
    }
    func_020e967c(arg0 + 0x1B4, arg0 + 0x1E4);
    func_020e956c(M2C_FIELD(arg0, s32 *, 0x1AC), arg0 + 0x1E4, arg0 + 0x220);
    func_020e92ac(M2C_FIELD(arg0, s32 *, 0x1AC), arg0 + 0x1E4, arg0 + 0x220, arg0 + 0x320, arg0 + 0x420);
    M2C_FIELD(arg0, s8 *, 0x1A5)  = 1;
    M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
    return 0;
}
