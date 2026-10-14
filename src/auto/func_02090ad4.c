#include "m2c.h"
#include "engine.h"

void func_02090af4(M2C_UNK);

extern s32 data_02137e88;

void func_02090ad4(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 >= 0x26) {
        var_r0 = 0x25;
    }
    data_02137e88 = var_r0;
    func_02090af4(var_r0);
}
