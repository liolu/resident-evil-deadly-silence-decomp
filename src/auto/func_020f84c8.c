/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020f84c8(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *lr;
    u8 *ip;
    u8 *q;
    u8 *pp;
    u16 off;
    u16 n;
    s32 v;

    lr                  = arg0 + *(s32 *) (arg0 + 8);
    off                 = *(u16 *) (lr + 0xA);
    ip                  = lr + 4;
    n                   = *(u16 *) (ip + off);
    q                   = ip + off + (n * arg1);
    pp                  = lr + *(s32 *) (q + 4);
    v                   = *(s32 *) (pp + 0xC);
    *(s32 *) (pp + 0xC) = (v & ~0x3F000000) | (arg2 << 0x18);
}
