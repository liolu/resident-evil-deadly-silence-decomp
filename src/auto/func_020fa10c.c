/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_02154608;

void func_020fa10c(u8 *arg0) {
    u8 *g;
    u8 *t;
    u8 *p1;
    u8 *p2;
    u8 *q;
    u8 *q2;
    u16 off6;
    u16 val;
    s32 off;

    g    = data_02154608;
    t    = *(u8 **) (g + 0xD4);
    off6 = *(u16 *) (t + 6);
    p1   = t + off6;
    val  = *(u16 *) (t + off6);
    p2   = p1 + val * ((u8 *) *(u8 **) g)[1];
    off  = *(s32 *) (p2 + 4);
    q    = t + off;
    if (*(u16 *) q & 1) {
        *(s32 *) arg0 = *(s32 *) arg0 | 4;
        return;
    }
    *(s32 *) (arg0 + 0x4C) = *(s32 *) (q + 4);
    q2                     = q + 4;
    *(s32 *) (arg0 + 0x50) = *(s32 *) (q2 + 4);
    *(s32 *) (arg0 + 0x54) = *(s32 *) (q2 + 8);
}
