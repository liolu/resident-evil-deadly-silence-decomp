/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213f2e8[];
extern u8 data_027e01bc[];
extern u8 data_027e01fc[];
void func_02106070(u16, void *, s32);
void func_020af7bc(s32, void *);

void func_020af7e8(s32 arg0) {
    volatile u16 sp0;
    void *var_r4;

    var_r4 = (arg0 == 0) ? data_027e01bc : data_027e01fc;
    sp0    = 0;
    func_02106070(sp0, data_0213f2e8 + (arg0 << 0xB), 0x800);
    func_020af7bc(arg0, var_r4);
}
