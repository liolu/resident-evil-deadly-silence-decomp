#include "engine.h"
#include "m2c.h"

s32 func_020e0d50(s32 arg0) {
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x58);
    }
    return 0;
}
