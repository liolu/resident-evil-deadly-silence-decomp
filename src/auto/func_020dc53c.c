/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e30fc(s32);                         /* extern */
M2C_UNK func_0211035c(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_020dc53c(void *arg0) {
    s32 temp_r0;

    if (arg0 == NULL) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_020e30fc(temp_r0);
    func_0211035c(arg0, 0, 0xEC);
    M2C_FIELD(arg0, s16 *, 0) = 0;
}
