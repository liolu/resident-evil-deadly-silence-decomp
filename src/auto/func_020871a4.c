/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020871a4(s32 arg0, s32 arg1) {
    u8 temp_r1;
    u8 var_r0;
    u8 var_r2;

    if (M2C_FIELD(arg1, u8 *, 7) == 4) {
        temp_r1 = M2C_FIELD(arg0, u8 *, 5);
        if (temp_r1 == 0) {
            return 1;
        }
        if ((temp_r1 == 2) && (M2C_FIELD(arg0, u8 *, 6) == 0)) {
            return 1;
        }
        return 0;
    }
    var_r2 = M2C_FIELD(arg0, u8 *, 5);
    if (var_r2 == 2) {
        var_r2 = M2C_FIELD(arg0, u8 *, 6);
    }
    var_r0 = M2C_FIELD(arg1, u8 *, 5);
    if (var_r0 == 2) {
        var_r0 = M2C_FIELD(arg1, u8 *, 6);
    }
    if (var_r2 != var_r0) {
        return 1;
    }
    return 0;
}
