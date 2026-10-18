/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_021486e0;

void func_02014d74(s32 arg0, u8 arg1) {
    M2C_UNK *var_ip;
    s32 var_r3;

    var_ip = &data_021486e0;
    var_r3 = 0;
    do {
        if ((M2C_FIELD(var_ip, u8 *, 0x12) != 0) && (M2C_FIELD(var_ip, u8 *, 0x14) == arg0)) {
            M2C_FIELD(var_ip, u8 *, 0x12) = arg1;
        }
        var_r3 += 1;
        var_ip = (M2C_UNK *) ((s8 *) var_ip + 0x58);
    } while (var_r3 < 8);
}
