/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_021486e0;

u8 *func_02014dac(s32 arg0, s32 arg1) {
    u8 *var_ip;
    s32 var_r3;

    var_r3 = 0;
    var_ip = (u8 *) &data_021486e0;
    goto check;
body:
    if (var_ip[0x12] != 0) {
        if (var_ip[0x14] == arg0) {
            if (var_ip[0x15] == arg1) {
                goto done;
            }
        }
    }
    var_r3 += 1;
    var_ip += 0x58;
check:
    if (var_r3 < 8) {
        goto body;
    }
done:
    if (var_r3 == 8) {
        return NULL;
    }
    return var_ip;
}
