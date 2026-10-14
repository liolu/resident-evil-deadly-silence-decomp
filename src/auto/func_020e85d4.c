/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8618(s8 *);                        /* extern */
extern s8 data_02153e00;

void func_020e85d4(void) {
    s32 var_r5;
    s8 *var_r4;

    var_r4 = &data_02153e00;
    var_r5 = 0;
    do {
        if (*var_r4 != 0) {
            func_020e8618(var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x38;
    } while (var_r5 < 4);
}
