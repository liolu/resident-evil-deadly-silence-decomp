#include "m2c.h"

void func_0200fa24(s32 arg0, s32 arg1, u16 *arg2) {
    s32 v;

    v = (*arg2 & ~0x3F00) | (arg0 << 8);
    if (arg1 != 0) {
        v |= 0x2000;
    }
    *arg2 = v;
}
