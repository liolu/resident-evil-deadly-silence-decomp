/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e03a4(s32 *);                           /* extern */
M2C_UNK func_020e04f8(s8 *);                        /* extern */
extern s32 data_0214f5f4;
extern s8 data_0214f600;

void func_020e046c(void) {
    s32 var_r5;
    s8 *var_r4;

    if (func_020e03a4(&data_0214f5f4) == 0) {
        return;
    }
    var_r4 = &data_0214f600;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020e04f8(var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x60;
    } while (var_r5 < 4);
    data_0214f5f4 = 0;
}
