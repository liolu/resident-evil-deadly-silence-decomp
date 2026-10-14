#include "m2c.h"
#include "engine.h"

void func_0204fde4(s32 arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x182) == 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
    M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) & ~2);
    M2C_FIELD(arg0, s16 *, 0x180) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x44) = (s16) M2C_FIELD(arg0, s16 *, 0x18E);
}
