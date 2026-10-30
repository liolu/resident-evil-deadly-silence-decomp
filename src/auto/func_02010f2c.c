/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02070438(s32);                         /* extern */
M2C_UNK func_020f7f1c();                            /* extern */

void func_02010f2c(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x20) != 0) {
        func_020f7f1c();
        func_02070438(M2C_FIELD(arg0, s32 *, 0x20));
        M2C_FIELD(arg0, s32 *, 0x20) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x84) != 0) {
        func_020f7f1c();
        func_02070438(M2C_FIELD(arg0, s32 *, 0x84));
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        func_020f7f1c();
        func_02070438(M2C_FIELD(arg0, s32 *, 0x7C));
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    }
}
