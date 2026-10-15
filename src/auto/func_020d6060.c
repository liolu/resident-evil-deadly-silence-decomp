#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;

s32 func_020d6060(s32 arg0) {
    u8 var_r2;

    if (arg0 != 0) {
        var_r2 = M2C_FIELD(&data_0213ae4c, u8 *, 2);
    } else {
        var_r2 = 0;
    }
    if ((var_r2 | (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x4010)) != 0) {
        return 1;
    }
    return 0;
}
