/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_02107cf0(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = 1;
    if (!((1 << arg0) & M2C_FIELD(((arg1 * 4) + 0x027FFC00), s32 *, 0x388))) {
        var_r3 = 0;
    }
    return var_r3;
}
