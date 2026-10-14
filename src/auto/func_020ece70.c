/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e45a8();                            /* extern */
M2C_UNK func_020e45b8();                            /* extern */
M2C_UNK func_020e45c8();                            /* extern */
s32 func_020ecd98(s32);                             /* extern */
M2C_UNK func_020ecdd0();                            /* extern */
extern s32 data_021368a8;

s32 func_020ece70(void) {
    u32 temp_r0;

    temp_r0 = func_020ecd98(data_021368a8) + 1;
    switch (temp_r0) {
    case 0:
    case 1:
        break;
    default:
        break;
    case 2:
        func_020ecdd0();
        break;
    case 3:
        func_020e45c8();
        break;
    case 4:
        func_020e45b8();
        func_020e45a8();
        break;
    }
    return 0;
}
