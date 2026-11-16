#include "m2c.h"

s32 func_020affd4(s8 *arg0, s8 *arg1) {
    s32 n0;
    s32 n1;
    s8 *p;
    s8 *q;

    n0 = 0;
    p  = arg0;
    goto c1;
b1:
    n0 += 1;
    p += 1;
c1:
    if (*p != 0) {
        goto b1;
    }
    n1 = 0;
    q  = arg1;
    goto c2;
b2:
    n1 += 1;
    q += 1;
c2:
    if (*q != 0) {
        goto b2;
    }
    return n0 == n1;
}
