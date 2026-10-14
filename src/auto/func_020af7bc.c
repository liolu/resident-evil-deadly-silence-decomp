#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213f2e8;

void func_020af7bc(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s16 *, 4) = 0;
    M2C_FIELD(arg1, void **, 0xC) = (void *) ((M2C_UNK *)((s8 *)&data_0213f2e8 + (arg0 << 0xB)));
    M2C_FIELD(arg1, s16 *, 6) = 0x800;
    M2C_FIELD(arg1, s8 *, 8) = 1;
}
