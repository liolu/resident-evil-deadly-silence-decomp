/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_021060a4(s32, M2C_UNK, s32);

void func_02017d38(M2C_UNK arg0, s32 arg1) {
    volatile s32 sp0;
    M2C_UNK a;

    a = arg0;
    if (arg1 != 0) {
        sp0 = 0;
        func_021060a4(sp0, a, arg1 * 0xBC);
    }
}
