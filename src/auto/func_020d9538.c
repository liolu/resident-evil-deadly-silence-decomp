/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020d9538(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 c;
    s8 r;
    s8 g;
    s8 b;

    c = *(u16 *) ((u8 *) arg0 + 0x50);
    r = (s8) ((c & 0x1F) + arg1);
    g = (s8) (arg2 + ((s32) (c & 0x3E0) >> 5));
    b = (s8) (arg3 + ((s32) (c & 0x7C00) >> 10));
    if (r > 0x1F) {
        r = 0x1F;
    }
    if (g > 0x1F) {
        g = 0x1F;
    }
    if (b > 0x1F) {
        b = 0x1F;
    }
    if (r < 0) {
        r = 0;
    }
    if (g < 0) {
        g = 0;
    }
    if (b < 0) {
        b = 0;
    }
    *(u16 *) ((u8 *) arg0 + 0x50) = (u16) (r | (g << 5) | (b << 10));
}
