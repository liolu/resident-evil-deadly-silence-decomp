/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020ecf54(M2C_UNK);
M2C_UNK func_020ed670(M2C_UNK);

s32 func_020ed06c(s32 arg0) {
    if (func_020ed670(arg0 + 0xC) != 3) {
        return 0;
    }
    if (func_020ecf54(arg0 + 0x4E254) == 0) {
        return 1;
    }
    return 0;
}
