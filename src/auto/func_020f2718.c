/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020f26f4(M2C_UNK);

s32 func_020f2718(s32 arg0) {
    if (func_020f26f4(arg0) == 0) {
        return 0;
    }
    return arg0 + (M2C_FIELD(arg0, s32 *, 0x1004) << 7);
}
