#include "engine.h"
#include "m2c.h"

void func_0210669c(M2C_UNK, M2C_UNK);

void func_0200e080(s32 arg0, s32 arg1) {
    s32 var_r1;

    if (arg1 < 0) {
        var_r1 = 0;
    } else {
        var_r1 = arg1 & 0x7F;
    }
    func_0210669c(arg0, var_r1);
}
