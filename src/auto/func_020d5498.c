/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

s32 func_020d5498(s32 arg0) {
    s32 var_r2;

    var_r2 = 1;
    if (!(*M2C_FIELD(&data_0213b890, u8 **, 0x4C) & (1 << arg0))) {
        var_r2 = 0;
    }
    return var_r2;
}
