/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020857ac(s32);
void func_02106070(u16, s32, s32);

void func_02085a94(s32 arg0) {
    volatile u16 sp0;

    sp0 = 0;
    func_02106070(sp0, arg0 + 0x10, 0x800);
    func_020857ac(arg0);
}
