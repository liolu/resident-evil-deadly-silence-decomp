#include "engine.h"
#include "m2c.h"

void func_02106618(M2C_UNK);

void func_0200e1c8(s32 arg0) {
    s32 var_r0;

    if (arg0 < 0) {
        var_r0 = 0;
    } else {
        var_r0 = arg0 & 0x7F;
    }
    func_02106618(var_r0);
}
