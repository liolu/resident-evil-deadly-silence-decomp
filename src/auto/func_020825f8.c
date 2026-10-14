#include "m2c.h"
#include "engine.h"

void func_020834cc(M2C_UNK);

void func_020825f8(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~0x20);
    func_020834cc(arg0);
}
