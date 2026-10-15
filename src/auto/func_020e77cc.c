/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020e77cc(s32 arg0) {
    if (arg0 == 0) {
        return -1;
    }
    if (M2C_FIELD(arg0, s8 *, 1) & 2) {
        return 1;
    }
    return 0;
}
