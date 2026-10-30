/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK VBlankIntrWait();                           /* extern */
M2C_UNK func_020e6630();                            /* extern */
M2C_UNK func_020e663c();                            /* extern */
extern s32 data_02137264;

void func_02005898(void) {
    if (data_02137264 != 0) {
        func_020e663c();
        func_020e6630();
        return;
    }
    VBlankIntrWait();
}
