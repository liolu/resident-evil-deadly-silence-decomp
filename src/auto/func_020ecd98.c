/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020e6170(void);

s32 func_020ecd98(s32 arg0) {
    if (arg0 != -1) {
        return arg0;
    }
    if (func_020e6170() == 1) {
        return 2;
    }
    return 1;
}
