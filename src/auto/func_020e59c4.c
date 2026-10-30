/* compiler: 2.0/sp1p5 -O4,s */
#include "m2c.h"

extern M2C_UNK data_02152cc4;

void *func_020e59c4(void) {
    s32 var_r2;

    var_r2 = 0;
loop_1:
    if (M2C_FIELD(((M2C_UNK *) ((s8 *) &data_02152cc4 + (var_r2 * 8))), s32 *, 4) != 0) {
        var_r2 += 1;
        if (var_r2 < 4) {
            goto loop_1;
        }
    }
    if (var_r2 == 4) {
        return NULL;
    }
    return (M2C_UNK *) ((s8 *) &data_02152cc4 + (var_r2 * 8));
}
