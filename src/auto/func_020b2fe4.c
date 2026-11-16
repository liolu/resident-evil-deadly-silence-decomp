#include "m2c.h"

extern u8 data_0213ad98[];
extern u8 *data_0213daa8;

s32 func_020b2fe4(void) {
    u8 *p;
    s32 a;
    s32 b;
    s32 r;

    p             = data_0213daa8;
    a             = data_0213ad98[0x12];
    b             = p[1];
    data_0213daa8 = p + 2;
    r             = a == b;
    return r;
}
