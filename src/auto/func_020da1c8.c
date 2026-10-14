/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020da22c(M2C_UNK);

extern s8 data_0214eb78;

void func_020da1c8(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_0214eb78;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020da22c((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x44;
    } while (var_r5 < 0x10);
}
