/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b2b4;

void func_0206fc08(s32 arg0) {
    s32 temp_r2;
    s32 var_r1;
    u8 var_r3;

    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        return;
    }
    temp_r2 = M2C_FIELD(arg0, u16 *, 4) * (M2C_FIELD(&data_0213b2b4, u8 *, 1) + 1);
    var_r3 = 1;
    if (M2C_FIELD(arg0, u8 *, 2) == 1) {
        var_r1 = M2C_FIELD(arg0, u16 *, 6) + temp_r2;
        if (var_r1 >= 0x1000) {
            var_r1 = 0x1000;
            var_r3 = 0;
        }
    } else {
        var_r1 = M2C_FIELD(arg0, u16 *, 6) - temp_r2;
        if (var_r1 < 0x100) {
            var_r1 = 0;
            var_r3 = 0;
        }
    }
    M2C_FIELD(arg0, u16 *, 6) = (u16) var_r1;
    M2C_FIELD(arg0, u8 *, 0) = var_r3;
}
