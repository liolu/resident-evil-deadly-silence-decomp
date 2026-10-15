#include "engine.h"
#include "m2c.h"

s32 func_02085378(s32 arg0, s32 arg1) {
    void *temp_r0;

    if ((u32) arg1 >= 0x10U) {
        return 0;
    }
    temp_r0 = M2C_FIELD(((arg1 * 0x1E8) + arg0), void **, 0x130);
    if (temp_r0 == NULL) {
        return 0;
    }
    if ((u32) M2C_FIELD(temp_r0, u8 *, 9) < 8U) {
        return 1;
    }
    return 0;
}
