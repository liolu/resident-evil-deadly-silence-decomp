/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_021486e0;

void func_02014d24(void) {
    M2C_UNK (*temp_r1)(M2C_UNK *);
    M2C_UNK *var_r5;
    s32 var_r4;

    var_r5 = &data_021486e0;
    var_r4 = 0;
    do {
        if (M2C_FIELD(var_r5, u8 *, 0x12) != 0) {
            temp_r1 = M2C_FIELD(var_r5, M2C_UNK(**)(M2C_UNK *), 4);
            if (temp_r1 != NULL) {
                temp_r1(var_r5);
            }
        }
        var_r4 += 1;
        var_r5 = (M2C_UNK *) ((s8 *) var_r5 + 0x58);
    } while (var_r4 < 8);
}
