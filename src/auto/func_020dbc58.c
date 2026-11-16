/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020e308c(void *, s32, s32, s32, s32);
M2C_UNK func_020e3070(void *);

void func_020dbc58(u8 *arg0, s32 arg1) {
    u8 *temp_r2;
    s32 temp_r4;
    s32 temp_r3;
    s32 temp_r2_b;

    temp_r2   = arg0 + 0x48;
    temp_r4   = M2C_FIELD(arg0, s32 *, 8);
    temp_r3   = M2C_FIELD(temp_r2, s32 *, 0x14) + (M2C_FIELD(temp_r2, s32 *, 0x20) * 2);
    temp_r2_b = temp_r3 + (M2C_FIELD(temp_r2, s32 *, 0x1C) * 2);
    func_020e308c((void *) temp_r4, M2C_FIELD(arg0, s32 *, 0x48), arg1 * 2, temp_r3, temp_r2_b);
    func_020e3070((void *) temp_r4);
}
