/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 data_02137298;

void *func_0200b688(s32 arg0) {
    u8 *var_r4;
    s32 var_lr;
    u8 *temp_ip;
    u8 *base;

    var_lr = (s32) (var_r4 = NULL);
    base   = (u8 *) (data_02137298 + 0x1440);
    do {
        temp_ip = base + (var_lr << 6);
        if ((arg0 == 0xFF) || (temp_ip[0x11] == arg0)) {
            if (var_r4 == NULL) {
                var_r4 = temp_ip;
            }
            if (temp_ip[0x10] < var_r4[0x10]) {
                var_r4 = temp_ip;
            }
        }
        var_lr += 1;
    } while (var_lr < 0x10);
    return var_r4;
}
