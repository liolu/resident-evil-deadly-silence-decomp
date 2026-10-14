#include "m2c.h"
#include "engine.h"

s32 func_020e0d8c(s32 arg0, s32 arg1) {
    s32 temp_r2;

    M2C_FIELD(arg0, volatile s32 *, 0x58) = arg1;
    temp_r2 = M2C_FIELD(arg0, volatile s32 *, 0x14);
    if ((s32) M2C_FIELD(arg0, volatile s32 *, 0x58) > temp_r2) {
        M2C_FIELD(arg0, volatile s32 *, 0x58) = temp_r2;
    }
    return M2C_FIELD(arg0, volatile s32 *, 0x58);
}
