#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad48;

void func_020a316c(s32 arg0) {
    if ((u32) (u8) ((u8) *M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 **, 4) + 0x24) > 1U) {
        return;
    }
    if (M2C_FIELD(&data_0213ad48, u8 *, 9) == 1) {
        M2C_FIELD(arg0, s16 *, 0x50) = 0x100;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x50) = 8;
}
