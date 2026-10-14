/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020ebd70();                            /* extern */
s32 func_020ebd88(s32, s32);                        /* extern */
M2C_UNK func_0211035c(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_020e9cc0(void *arg0) {
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x1B0);
    func_0211035c(arg0 + 0x1B4, 0, 0x30);
    func_0211035c(arg0 + 0x1E4, 0, 0x3C);
    func_0211035c(arg0 + 0x220, 0, 0x100);
    func_0211035c(arg0 + 0x320, 0, 0x100);
    func_0211035c(arg0 + 0x420, 0, 0x300);
    func_0211035c(M2C_FIELD(arg0, void **, 0), 0, 0x180);
    func_0211035c(arg0 + 0x720, 0, 0x300);
    M2C_FIELD(arg0, s8 *, 0x1A5) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A8) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1B0) == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x1B0) = 0;
    func_020ebd70();
    M2C_FIELD(arg0, s32 *, 0x1B0) = func_020ebd88(temp_r4, 0x101C);
}
