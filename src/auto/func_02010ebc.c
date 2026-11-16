/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020703b8(s32);                             /* extern */
M2C_UNK func_020761b8(s32);                         /* extern */
M2C_UNK func_020f4658(void *, void *);              /* extern */
M2C_UNK func_020f83a8(void *, s32);                 /* extern */
M2C_UNK func_020f86e8(void *, M2C_UNK, M2C_UNK);    /* extern */
void *func_020f8798(s32);                           /* extern */

void func_02010ebc(s32 arg0, void *arg1) {
    s32 temp_r0;
    void *temp_r0_2;
    void *temp_r4;

    temp_r0                      = func_020703b8(arg0);
    M2C_FIELD(arg1, s32 *, 0x20) = temp_r0;
    func_020761b8(temp_r0);
    temp_r0_2                      = func_020f8798(temp_r0);
    temp_r4                        = temp_r0_2 + M2C_FIELD((temp_r0_2 + M2C_FIELD(temp_r0_2, u16 *, 0xE)), s32 *, 0xC);
    M2C_FIELD(arg1, void **, 0x24) = temp_r4;
    func_020f4658(arg1 + 0x28, temp_r4);
    func_020f83a8(temp_r4, 0x7FFF);
    func_020f86e8(temp_r4, 1, 0x400);
}
