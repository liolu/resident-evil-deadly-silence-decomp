#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_0208844c(void) {
    s32 var_r0;

    var_r0 = 1;
    if (M2C_FIELD(&data_021375ac, u16 *, 0x4C) == 1) {
        return 1;
    }
    if (M2C_FIELD(&data_021375ac, u16 *, 0x4C) != 3) {
        var_r0 = 0;
    }
    return var_r0;
}
