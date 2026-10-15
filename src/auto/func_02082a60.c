#include "engine.h"
#include "m2c.h"

void func_020834cc(M2C_UNK);

void func_02082a60(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~0x40);
    func_020834cc(arg0);
}
