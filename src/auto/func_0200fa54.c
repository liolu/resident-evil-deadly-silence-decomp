#include "m2c.h"

void func_0200fa54(s32 arg0, s32 arg1, u16 *arg2) {
    s32 v;

    v = (*arg2 & ~0x3F) | arg0;
    if (arg1 != 0) {
        v |= 0x20;
    }
    *arg2 = v;
}
