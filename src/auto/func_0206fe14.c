/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020702c0(M2C_UNK, M2C_UNK, M2C_UNK);
void func_02070438(M2C_UNK);
M2C_UNK func_020704b0(M2C_UNK);

extern M2C_UNK data_0213ad74;

s32 func_0206fe14(s32 arg0, s32 arg1) {
    s32 var_r4;
    s32 var_r5;

    var_r5 = arg1;
    if (var_r5 != 0) {
        var_r4 = 0;
    } else {
        var_r5 = func_020704b0(M2C_FIELD(&data_0213ad74, s32 *, 0xC));
        var_r4 = 1;
    }
    if (func_020702c0(arg0, var_r5, M2C_FIELD(&data_0213ad74, s32 *, 0xC)) == 0) {
        if (var_r4 != 0) {
            func_02070438(var_r5);
        }
        var_r5 = 0;
    }
    return var_r5;
}
