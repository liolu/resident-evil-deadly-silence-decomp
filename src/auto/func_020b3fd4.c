/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern M2C_UNK data_0214bcc0;

s32 func_020b3fd4(void) {
    u8 *var_r5;
    u8 temp_r4;
    u8 temp_lr;
    s32 temp_r3;
    u8 *var_ip;

    var_r5                                                                                            = data_0213daa8;
    temp_r3                                                                                           = var_r5[1];
    temp_r4                                                                                           = var_r5[2];
    temp_lr                                                                                           = var_r5[3];
    var_ip                                                                                            = var_r5 + 4;
    temp_r3                                                                                           = temp_r3 * 0x14;
    data_0213daa8                                                                                     = var_ip;
    *(s16 *) ((u8 *) M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u8 **, 0x48) + temp_r3 + 2) = (s16) temp_r4;
    *(s16 *) ((u8 *) M2C_FIELD(M2C_FIELD(&data_0214bcc0, void **, 0x7AC), u8 **, 0x48) + temp_r3)     = (s16) temp_lr;
    return 1;
}
