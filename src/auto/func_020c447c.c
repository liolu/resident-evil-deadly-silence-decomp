#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

s32 func_020c447c(void) {
    s32 var_r0;

    var_r0 = 0;
    if (M2C_FIELD(&data_0213b890, s32 *, 0x84) != M2C_FIELD(&data_0213b890, s32 *, 0x74)) {
        var_r0 = 1;
    }
    if (M2C_FIELD(&data_0213b890, s32 *, 0x88) != M2C_FIELD(&data_0213b890, s32 *, 0x78)) {
        var_r0 = 1;
    }
    if (M2C_FIELD(&data_0213b890, s32 *, 0x8C) != M2C_FIELD(&data_0213b890, s32 *, 0x7C)) {
        var_r0 = 1;
    }
    return var_r0;
}
