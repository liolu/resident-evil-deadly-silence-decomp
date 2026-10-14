#include "m2c.h"
#include "engine.h"

s32 func_020ecf04(s32 arg0) {
    return (M2C_FIELD(arg0, s32 *, 0x18414) * 0xC208) + arg0;
}
