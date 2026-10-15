#include "engine.h"
#include "m2c.h"

extern void *data_027e000c;

s32 func_020d9818(s32 arg0) {
    u8 var_r0;

    if ((s32) (((M2C_FIELD(arg0, s16 *, 0x44) - M2C_FIELD(data_027e000c, s16 *, 0x44)) + 0x400) & 0xFFF) < 0x800) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (s32) var_r0;
}
