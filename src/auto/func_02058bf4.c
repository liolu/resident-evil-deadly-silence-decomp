#include "m2c.h"

s32 func_02058bf4(void *arg0) {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r3_5;
    void *temp_r3_6;

    temp_r3                           = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3, s32 *, 0x30)   = (s32) (M2C_FIELD(temp_r3, s32 *, 0x30) + M2C_FIELD(temp_r3, s16 *, 0x48));
    temp_r3_2                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_2, s32 *, 0x34) = (s32) (M2C_FIELD(temp_r3_2, s32 *, 0x34) + M2C_FIELD(temp_r3_2, s16 *, 0x4A));
    temp_r3_3                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_3, s32 *, 0x38) = (s32) (M2C_FIELD(temp_r3_3, s32 *, 0x38) + M2C_FIELD(temp_r3_3, s16 *, 0x4C));
    temp_r3_4                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_4, s16 *, 0x42) = (s16) (M2C_FIELD(temp_r3_4, s16 *, 0x42) + M2C_FIELD(temp_r3_4, s16 *, 0x8C));
    temp_r3_5                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_5, s16 *, 0x44) = (s16) (M2C_FIELD(temp_r3_5, s16 *, 0x44) + M2C_FIELD(temp_r3_5, s16 *, 0x8E));
    temp_r3_6                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r3_6, s16 *, 0x46) = (s16) (M2C_FIELD(temp_r3_6, s16 *, 0x46) + M2C_FIELD(temp_r3_6, s16 *, 0x90));
    return 1;
}
