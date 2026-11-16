/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213b890;

s32 func_020bf7f0(s32 arg0) {
    u32 var_lr;
    s8 *temp_ip;
    u8 temp_r3;

    temp_ip = (s8 *) M2C_FIELD(&data_0213b890, u8 **, 0x4C);
    temp_r3 = (u8) temp_ip[0x12];
    temp_ip = temp_ip + temp_r3 * 6;
    var_lr  = 0;
    goto check;
body:
    if (temp_ip[var_lr] != -1) {
        if (var_lr == arg0) {
            return 1;
        }
    }
    var_lr = (u8) (var_lr + 1);
check:
    if (var_lr < 6U) {
        goto body;
    }
    return 0;
}
