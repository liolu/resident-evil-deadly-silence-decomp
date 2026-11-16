#include "m2c.h"

void func_020b3a24(u32 *arg0, u32 arg1) {
    u32 i   = arg1 >> 5;
    arg0[i] = arg0[i] | (1 << (31 - (arg1 & 31)));
}
