#include "m2c.h"
#include "engine.h"

M2C_UNK func_02107e90(M2C_UNK, M2C_UNK);

void func_02108910(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) | 4);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x32) = 0;
    M2C_FIELD(arg0, s16 *, 0x30) = (s16) arg1;
    func_02107e90(arg0, 2);
}
