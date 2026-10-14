/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f2c5c(s32);                         /* extern */
s32 func_020f2c68(s32, s32, M2C_UNK);               /* extern */
M2C_UNK func_020f3204(void *, s32, M2C_UNK);        /* extern */

void func_02078478(void *arg0) {
    func_020f2c5c(M2C_FIELD(arg0, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 8) = func_020f2c68(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0), 1);
    func_020f3204(arg0 + 0xC, M2C_FIELD(arg0, s32 *, 8), 4);
}
