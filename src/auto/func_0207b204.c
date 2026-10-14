/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0207c828(void **);                     /* extern */
M2C_UNK func_020884e0(M2C_UNK);                     /* extern */
M2C_UNK func_02090450(u8);                          /* extern */

void func_0207b204(void **arg0) {
    void *temp_r4;

    temp_r4 = *arg0;
    func_02090450(M2C_FIELD(temp_r4, u8 *, 0x17C));
    M2C_FIELD(temp_r4, u8 *, 0x17C) = 0U;
    func_0207c828(arg0);
    func_020884e0(0);
}
