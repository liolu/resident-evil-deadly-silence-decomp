#include "m2c.h"
s32 func_020f8b40(s32 a0, s32 a1) {
    s32 p    = a0 + *(s32 *) (a0 + *(u16 *) (a0 + 0xc));
    s32 off  = *(u16 *) (p + 0xe);
    s32 base = p + 8 + off;
    s32 v    = *(u16 *) base;
    s32 q    = base + 4 + v * a1;
    if (q != 0) {
        return p + *(s32 *) q;
    }
    return 0;
}
