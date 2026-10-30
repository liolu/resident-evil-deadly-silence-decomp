/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02017b7c(void *);                        /* extern */
M2C_UNK func_02017c64(void *);                      /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_021489a0;

void func_0207c794(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r2;
    s32 var_r7;
    void *temp_r0;
    void *temp_r6;

    var_r7 = 0;
    do {
        temp_r2 = var_r7 * 0xBC;
        temp_r0 = (M2C_UNK *) ((s8 *) &data_02143cc0 + temp_r2);
        if ((M2C_FIELD(temp_r0, u8 *, 0x4CE0) != 0) && (arg0 == M2C_FIELD(temp_r0, u8 *, 0x4D06)) &&
            (arg1 == M2C_FIELD(temp_r0, u8 *, 0x4D07))) {
            temp_r6 = (M2C_UNK *) ((s8 *) &data_021489a0 + temp_r2);
            if (arg2 == M2C_FIELD(func_02017b7c(temp_r6), s16 *, 0x12)) {
                func_02017c64(temp_r6);
            }
        }
        var_r7 += 1;
    } while (var_r7 < 0x50);
}
