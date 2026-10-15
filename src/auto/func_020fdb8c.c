#include "engine.h"
#include "m2c.h"

s32 func_020fdb8c(s32 arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 8) >= (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        return 1;
    }
    return 0;
}
