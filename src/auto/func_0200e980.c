#include "m2c.h"

s32 func_0200e980(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;

    var_r0 = arg0;
    if (arg1 > var_r0) {
        return arg1;
    }
    if (arg2 < var_r0) {
        var_r0 = arg2;
    }
    return var_r0;
}
