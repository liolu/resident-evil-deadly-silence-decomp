/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020abdb4(u8, u8, void *); /* extern */
extern u8 data_0212e7c4[];

void func_02091b70(u8 *arg0) {
    u8 sp0[4];
    u8 *src;
    u8 *dst;
    u32 n;

    src = data_0212e7c4;
    dst = sp0;
    n   = 4;
    do {
        *dst++ = *src++;
        n--;
    } while (n != 0);
    func_020abdb4(arg0[9], sp0[(u16) (((s32) * (u16 *) (arg0 + 0x37A) >> 0xE) & 3)], arg0 + 0x30);
}
