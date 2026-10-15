/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e6f98(M2C_UNK);

extern s8 data_02153360;

void func_020e6870(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_02153360;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020e6f98((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x238;
    } while (var_r5 < 4);
}
