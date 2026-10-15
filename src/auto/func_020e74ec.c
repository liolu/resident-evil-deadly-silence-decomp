/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e7534(M2C_UNK);
void func_020e8794(void);

extern s8 data_02153c48;

void func_020e74ec(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_02153c48;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020e7534((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x50;
    } while (var_r5 < 2);
    func_020e8794();
}
