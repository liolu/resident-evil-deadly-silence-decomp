/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e7314(s32);                             /* extern */
M2C_UNK func_020e7320(s32, M2C_UNK);                /* extern */
extern s32 data_0214f794;

void func_020e22e0(void *arg0) {
    data_0214f794 = func_020e7314(M2C_FIELD(arg0, s32 *, 0xC));
    if (func_020e7314(M2C_FIELD(arg0, s32 *, 0xC)) > 0) {
        return;
    }
    func_020e7320(M2C_FIELD(arg0, s32 *, 0xC), 0);
    M2C_FIELD(arg0, s8 *, 1) = 5;
}
