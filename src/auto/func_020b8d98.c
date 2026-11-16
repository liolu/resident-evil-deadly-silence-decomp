#include "m2c.h"

extern u16 data_0213ad30[];

s32 func_020b8d98(s32 arg0) {
    s32 r = 0;
    if (arg0 != 0) {
        r |= (data_0213ad30[1] != 0) ? 1 : r;
    }
    return r | (data_0213ad30[1] & 8);
}
