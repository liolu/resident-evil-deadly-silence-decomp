/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0211ba48;

void func_02003a98(void);

void func_0200f768(s32 arg0) {
    u16 *p;

    *(volatile u32 *) 0x04000000 = *(volatile u32 *) 0x04000000 & ~0x1F00;
    *(volatile u16 *) 0x04000050 = 0;
    p                            = (u16 *) ((u8 *) &data_0211ba48 + arg0 * 8);
    *(volatile u16 *) 0x04000008 = p[0];
    *(volatile u16 *) 0x0400000A = p[1];
    *(volatile u16 *) 0x0400000C = p[2];
    *(volatile u16 *) 0x0400000E = p[3];
    func_02003a98();
}
