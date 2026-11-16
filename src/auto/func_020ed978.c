#include "m2c.h"

void func_020ed978(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p;

    p       = (s32 *) arg0;
    p[arg1] = arg2;
    p       = (s32 *) (arg0 + (arg1 * 4));
    p[3]    = arg3;
}
