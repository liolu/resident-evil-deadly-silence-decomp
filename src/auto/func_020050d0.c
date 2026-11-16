/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_02137264;

s32 func_020050d0(void) {
    u32 *src;
    u32 *dst;
    u32 r0;
    u32 r5;
    s32 n;
    s32 a;
    s32 b;

    src = *(u32 **) (data_02137264 + 0x54C);
    a   = 0x100 - *(u16 *) (data_02137264 + 0x16);
    b   = 0xC0 - *(u16 *) (data_02137264 + 0x18);
    r5  = (u32) (a + (b << 8)) >> 1;
    r0  = 0;
    while (r0 < *(u16 *) (data_02137264 + 0x18)) {
        dst = (u32 *) ((u8 *) (data_02137264 + 0x8C164) + (r5 + (r0 << 8)));
        n   = *(u16 *) (data_02137264 + 0x16) >> 2;
        while (n-- != 0) {
            *dst = *src;
            dst++;
            src++;
        }
        r0++;
    }
    return 0xC000;
}
