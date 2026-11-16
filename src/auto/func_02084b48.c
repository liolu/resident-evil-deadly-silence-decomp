#include "m2c.h"
s32 Sqrt(s32);

s32 func_02084b48(s32 **arg0, s32 *arg1) {
    s32 *p;
    s32 dy;
    s32 dx;

    p  = *arg0;
    dx = p[12] - arg1[0];
    dy = p[14] - arg1[2];
    return Sqrt((dx * dx) + (dy * dy));
}
