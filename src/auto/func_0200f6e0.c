/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0211b970;

void func_020ff1e8(s32 a);

void func_0200f6e0(s32 arg0) {
    u16 *p;

    *(volatile u32 *) 0x04001000 = *(volatile u32 *) 0x04001000 & ~0x1F00;
    *(volatile u16 *) 0x04001050 = 0;
    func_020ff1e8(0);
    p                            = (u16 *) ((u8 *) &data_0211b970 + arg0 * 8);
    *(volatile u16 *) 0x04001008 = p[0];
    *(volatile u16 *) 0x0400100A = p[1];
    *(volatile u16 *) 0x0400100C = p[2];
    *(volatile u16 *) 0x0400100E = p[3];
}
