#include "engine.h"
#include "m2c.h"

extern void *data_02137264;

s32 func_02005be4(void) {
    s32 var_r0;

    if (data_02137264 != NULL) {
        if (M2C_FIELD(data_02137264, s16 *, 6) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}
