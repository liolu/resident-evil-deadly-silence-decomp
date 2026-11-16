/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_021375ac;

void func_02089ad4(void) {
    s32 var_lr;
    s32 temp_r3;
    s32 temp_r0;
    s8 temp_r2;

    var_lr = 0;
    do {
        *(s8 *) ((M2C_FIELD(&data_021375ac, s32 *, 0x64) + var_lr) + 0x2CC4) = 0x20;
        temp_r3                                                              = M2C_FIELD(&data_021375ac, s32 *, 0x64) + var_lr;
        temp_r2                                                              = *(s8 *) (temp_r3 + 0x2CC4);
        temp_r0                                                              = temp_r3 + 0x2000;
        *(s8 *) (temp_r0 + 0xCAC)                                            = temp_r2;
        var_lr += 1;
    } while (var_lr < 0x18);
}
