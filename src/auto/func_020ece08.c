/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e45c8();                            /* extern */
M2C_UNK func_020e45e8();                            /* extern */
M2C_UNK func_020e45f8();                            /* extern */
M2C_UNK func_020e4608();                            /* extern */
M2C_UNK func_020e4618();                            /* extern */
s32 func_020ecd98(s32);                             /* extern */
extern s32 data_021368a8;

s32 func_020ece08(void) {
    u32 temp_r0;

    temp_r0 = func_020ecd98(data_021368a8) + 1;
    switch (temp_r0) {
        case 0:
        case 1:
        case 2:
            break;
        default:
            break;
        case 3:
            func_020e4618();
            break;
        case 4:
            func_020e4618();
            func_020e4608();
            func_020e45f8();
            func_020e45e8();
            func_020e45c8();
            break;
    }
    return 0;
}
