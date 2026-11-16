#include "m2c.h"

void func_020b3a00(u32 *arg0, u32 arg1) {
    u32 idx   = arg1 >> 5;
    arg0[idx] = arg0[idx] & ~(1u << (0x1F - (arg1 & 0x1F)));
}
