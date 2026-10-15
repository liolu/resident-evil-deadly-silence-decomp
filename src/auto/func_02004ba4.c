#include "engine.h"
#include "m2c.h"

extern u8 data_02136ea4;

s32 func_02004ba4(s32 arg0) {
    u8 temp_r0;

    temp_r0 = data_02136ea4;
    if ((u32) M2C_FIELD(arg0, u8 *, 0x1E) > (u32) temp_r0) {
        data_02136ea4 = temp_r0 + 1;
        return (s32) temp_r0;
    }
    return -1;
}
