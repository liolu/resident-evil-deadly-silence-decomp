/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_021060e8(s32, void *, s32); /* extern */
extern u8 data_0213d1c0[];
extern u8 data_0213d234[];
extern u8 data_0213d6a8[];

void func_0200642c(void) {
    volatile s32 sp0;
    volatile s32 sp4;

    sp0                  = 0x2C0;
    data_0213d1c0[0]     = 0;
    data_0213d1c0[0x474] = 0;
    func_021060e8(sp0, data_0213d234, 0x400);
    sp4 = 0x2C0;
    func_021060e8(sp4, data_0213d6a8, 0x400);
}
