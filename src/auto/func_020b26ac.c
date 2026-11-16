/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213adac;
extern u8 *data_0213daa8;
extern M2C_UNK data_0213dca8;

s32 func_020b26ac(void) {
    u8 *temp_r2;
    u32 temp_lr;
    u16 temp_ip;
    u32 temp_r2_idx;

    temp_r2                                        = data_0213daa8;
    temp_lr                                        = temp_r2[1];
    temp_ip                                        = *(u16 *) (temp_r2 + 2);
    data_0213daa8                                  = temp_r2 + 4;
    temp_r2_idx                                    = temp_lr * 2;
    *(u16 *) ((u8 *) &data_0213adac + temp_r2_idx) = temp_ip;
    if (temp_lr == 4) {
        M2C_FIELD(&data_0213dca8, s16 *, 0x4C) = 0;
    }
    return 1;
}
