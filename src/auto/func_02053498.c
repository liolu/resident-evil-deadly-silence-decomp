#include "m2c.h"
#include "engine.h"

void func_02053498(s32 arg0) {
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
    if (M2C_FIELD(arg0, s16 *, 0xA8) == 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
    }
}
