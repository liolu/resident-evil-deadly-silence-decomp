/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_0214bcc0;

void func_020a0600(s32 arg0) {
    u32 var_r5;
    u8 *temp_r4;

    for (var_r5 = 0; var_r5 < (u32) *M2C_FIELD(&data_0214bcc0, u8 **, 0x7AC); var_r5++) {
        temp_r4 = (u8 *) &data_02143cc0 + (var_r5 * 0x38);
        if (arg0 == temp_r4[0xA9]) {
            temp_r4[0xA8] = 1;
        }
    }
}
