#include "m2c.h"
#include "engine.h"

void func_02082df8(M2C_UNK);

void func_02082690(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) | 0x20);
    func_02082df8(arg0);
}
