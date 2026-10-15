/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020848ec(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(*(M2C_UNK *) arg0, s16 *, 0x42) = (s16) (M2C_FIELD(arg1, s16 *, 0) & 0xFFF);
    M2C_FIELD(*(M2C_UNK *) arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg1, s16 *, 2) & 0xFFF);
    M2C_FIELD(*(M2C_UNK *) arg0, s16 *, 0x46) = (s16) (M2C_FIELD(arg1, s16 *, 4) & 0xFFF);
    M2C_FIELD(*(M2C_UNK *) arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(*(M2C_UNK *) arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(*(M2C_UNK *) arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg2, s32 *, 8);
}
