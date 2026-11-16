#include "m2c.h"

s32 func_020b39e4(s32 *arg0, u32 arg1) {
    return arg0[arg1 >> 5] & (1 << (31 - (arg1 & 31)));
}
