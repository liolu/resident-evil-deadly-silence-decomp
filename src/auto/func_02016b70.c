#include "engine.h"
#include "m2c.h"

void func_02016a94(M2C_UNK);

void func_02016b70(s32 arg0) {
    M2C_FIELD(arg0, s16 *, 0x28) = (s16) (M2C_FIELD(arg0, s16 *, 0x28) + (M2C_FIELD(arg0, s8 *, 4) * 2));
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16) (M2C_FIELD(arg0, s16 *, 0x2A) + (M2C_FIELD(arg0, s8 *, 5) * 2));
    M2C_FIELD(arg0, s16 *, 0x2C) = (s16) (M2C_FIELD(arg0, s16 *, 0x2C) + (M2C_FIELD(arg0, s8 *, 6) * 2));
    func_02016a94(arg0);
}
