#include "engine.h"
#include "m2c.h"

extern u8 data_02137374;

s32 func_020478fc(void) {
    u8 var_r0;

    if (data_02137374 != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (s32) var_r0;
}
