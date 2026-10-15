#include "engine.h"
#include "m2c.h"

s32 func_020ecf34(s32 arg0) {
    return M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0x18414) * 0xC208) + arg0), s32 *, 0xC204);
}
