#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02143cc0;

void func_0208c820(s32 arg0, s32 arg1) {
    s8 var_r1;

    M2C_FIELD(arg0, s8 *, 0x179) = (s8) arg1;
    if (arg1 == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = var_r1;
}
