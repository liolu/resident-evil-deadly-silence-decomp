/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213e394[];
extern u8 data_0213f2e8[];
void func_02106070(u16, void *, s32);

void func_02092060(void) {
    volatile u16 sp0;

    sp0 = 0;
    func_02106070(sp0, data_0213f2e8 + ((data_0213e394[0x17] + (data_0213e394[0x18] << 5)) * 2), 0x100);
    data_0213e394[0x2A] = 1;
}
