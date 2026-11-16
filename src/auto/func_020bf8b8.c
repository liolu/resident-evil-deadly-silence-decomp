/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_02106070(s32, void *, s32);
extern u8 data_0213f2e8[];
extern u8 data_0213fae8[];
extern u8 data_027e01bc[];
extern u8 data_027e01fc[];

void func_020bf8b8(s32 arg0) {
    volatile u16 sp0;
    u8 *r5;
    u8 *r4;

    if (arg0 == 0) {
        r5 = data_0213f2e8;
        r4 = data_027e01bc;
    } else {
        r5 = data_0213fae8;
        r4 = data_027e01fc;
    }
    sp0 = 0;
    func_02106070(sp0, r5, 0x600);
    *(u16 *) (r4 + 4)   = 0;
    *(u8 **) (r4 + 0xC) = r5;
    *(u16 *) (r4 + 6)   = 0x600;
    r4[8]               = 1;
}
