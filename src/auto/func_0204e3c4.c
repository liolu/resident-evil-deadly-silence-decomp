#include "engine.h"
#include "m2c.h"

void func_0204aeec(M2C_UNK);

void func_0204e3c4(s32 arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x91) == 0) {
        M2C_FIELD(arg0, s8 *, 0x90) = 3;
        M2C_FIELD(arg0, u8 *, 0x91) = 1U;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
    }
    func_0204aeec(arg0);
}
