/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_020ca464(s32 arg0, s32 arg1) {
    if ((arg1 == 0) && (arg0 == -1)) {
        return 8;
    }
    if ((arg1 == 8) && (arg0 == 1)) {
        return 0;
    }
    return (s32) (u8) (arg1 + arg0);
}
