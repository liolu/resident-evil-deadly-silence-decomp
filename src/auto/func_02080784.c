/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020801c4(void **);
M2C_UNK func_020801d0(void **);
M2C_UNK func_02080620();

void func_02080784(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x90);
    switch (temp_r1) {
        case 0:
            func_02080620();
        /* fallthrough */
        case 1:
            func_020801d0(arg0);
            return;
        case 2:
            func_020801c4(arg0);
            return;
        default:
            func_020801c4(arg0);
            return;
        case 3:
            return;
    }
}
