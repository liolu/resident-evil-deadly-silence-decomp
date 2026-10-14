/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0210aca0(s32 arg0) {
    s32 var_r4;

    var_r4 = arg0;
    if (var_r4 == 0) {
        return;
    }
    do {
        M2C_FIELD(var_r4, M2C_UNK (**)(s32), 0)(M2C_FIELD(var_r4, s32 *, 4));
        var_r4 = M2C_FIELD(var_r4, s32 *, 8);
    } while (var_r4 != 0);
}
