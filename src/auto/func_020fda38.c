#include "m2c.h"
#include "engine.h"

void func_020fda38(s32 arg0) {
    s32 *temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 **, 0x148);
    if (temp_r2 != NULL) {
        *temp_r2 = 0;
        M2C_FIELD(arg0, s32 **, 0x148) = NULL;
    }
    M2C_FIELD(arg0, volatile s32 *, 0x10C) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x10C) & ~1);
    M2C_FIELD(arg0, volatile s32 *, 0x10C) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x10C) & ~4);
    M2C_FIELD(arg0, volatile s32 *, 0x10C) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x10C) & ~2);
}
