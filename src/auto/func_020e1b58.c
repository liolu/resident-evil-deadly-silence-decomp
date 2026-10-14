/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e1bbc(M2C_UNK);

extern s8 data_0214f308;

void func_020e1b58(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_0214f308;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020e1bbc((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0xC4;
    } while (var_r5 < 2);
}
