/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020cbd18(s32 arg0, s32 arg1, s32 arg2) {
    if ((u32) (arg2 * 2) >= (u32) (arg2 + (arg0 - arg1))) {
        return 1;
    }
    return 0;
}
