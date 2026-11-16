/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020f8510(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *lr;
    u8 *ip;
    u8 *p;
    u16 r0;
    u16 r3;
    s32 off;
    s32 t;

    lr                              = arg0 + M2C_FIELD(arg0, s32 *, 8);
    r0                              = M2C_FIELD(lr, u16 *, 0xA);
    ip                              = lr + 4;
    r3                              = *(u16 *) (ip + r0);
    p                               = ip + r0 + (r3 * arg1);
    off                             = M2C_FIELD(p, s32 *, 4);
    t                               = M2C_FIELD(lr + off, s32 *, 0xC) & ~0xF;
    M2C_FIELD(lr + off, s32 *, 0xC) = t | arg2;
}
