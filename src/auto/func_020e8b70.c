#include "engine.h"
#include "m2c.h"

s32 func_020e8b70(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 8);
}
