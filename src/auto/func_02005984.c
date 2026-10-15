#include "engine.h"
#include "m2c.h"

extern void *data_02137264;

s32 func_02005984(void) {
    s32 var_r0;

    var_r0 = 0;
    if (data_02137264 == NULL) {
        return 0;
    }
    if (M2C_FIELD(data_02137264, s32 *, 0xC) != 1) {
        var_r0 = 1;
    }
    return var_r0;
}
