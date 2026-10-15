#include "m2c.h"

s32 func_02058cb8(void *arg0) {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;

    temp_r3                           = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3, s32 *, 0x30)   = (s32) (M2C_FIELD(temp_r3, s32 *, 0x30) + M2C_FIELD(temp_r3, s16 *, 0x48));
    temp_r3_2                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_2, s32 *, 0x34) = (s32) (M2C_FIELD(temp_r3_2, s32 *, 0x34) + M2C_FIELD(temp_r3_2, s16 *, 0x4A));
    temp_r3_3                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_3, s32 *, 0x38) = (s32) (M2C_FIELD(temp_r3_3, s32 *, 0x38) + M2C_FIELD(temp_r3_3, s16 *, 0x4C));
    return 1;
}
