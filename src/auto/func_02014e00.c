/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_021486e0;
extern M2C_UNK data_0214bcc0;

M2C_UNK *func_02014e00(s8 arg0) {
    u8 *var_r3;
    u32 var_r2;

    for (var_r2 = 0, var_r3 = (u8 *) &data_021486e0; var_r2 < 8U; var_r2++, var_r3 += 0x58) {
        if (*(var_r3 + 0x12) == 0) {
            *(var_r3 + 0x12)                        = 1U;
            *(s8 *) (var_r3 + 0x14)                 = arg0;
            *(u8 *) ((u8 *) &data_0214bcc0 + 0x7A2) = (u8) (*(u8 *) ((u8 *) &data_0214bcc0 + 0x7A2) + 1);
            return (M2C_UNK *) var_r3;
        }
    }
    return NULL;
}
