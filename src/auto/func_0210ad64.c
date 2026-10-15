#include "engine.h"
#include "m2c.h"

void func_0210ad64(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        M2C_FIELD(arg1, s32 *, 8) = (s32) * (M2C_UNK *) arg0;
        *(M2C_UNK *) arg0         = arg1;
    }
}
