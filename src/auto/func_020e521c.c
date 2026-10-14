/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e5260(M2C_UNK);

extern s8 data_021528c0;

void func_020e521c(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_021528c0;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020e5260((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x7C;
    } while (var_r5 < 4);
}
