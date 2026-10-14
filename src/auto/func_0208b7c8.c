#include "m2c.h"
#include "engine.h"

s32 func_0208b7c8(s32 arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x2B4), u8 *, 6);
    if ((temp_r1 != 0) && ((s32) temp_r1 <= (s32) M2C_FIELD(arg0, s16 *, 0x28A))) {
        return 1;
    }
    return 0;
}
