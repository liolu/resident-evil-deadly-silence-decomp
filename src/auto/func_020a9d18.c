/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02074ef0(M2C_UNK);

extern M2C_UNK data_02143cc0;

s32 func_020a9d18(void) {
    u8 var_r0;

    var_r0 = M2C_FIELD(&data_02143cc0, u8 *, 0xF4E);
    if (var_r0 == 4) {
        var_r0 = 2;
    }
    if (func_02074ef0((s32) (u8) (var_r0 + 9)) >= 0) {
        return 1;
    }
    return 0;
}
