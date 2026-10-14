#include "m2c.h"
#include "engine.h"

void func_02082b40(M2C_UNK);

void func_0207cf34(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) | 0x40);
    func_02082b40(arg0);
}
