/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 data_02137264;

M2C_UNK func_02005648();
M2C_UNK func_021060a4();

void func_020055f8(void) {
    volatile s32 sp0;

    if (data_02137264 != 0) {
        func_02005648();
        sp0 = 0;
        func_021060a4(sp0, data_02137264 + 0x14, 0x98150);
    }
}
