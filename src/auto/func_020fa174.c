/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f9b5c(void *, M2C_UNK, s32, M2C_UNK); /* extern */

void func_020fa174(M2C_UNK arg0, void *arg1, M2C_UNK arg2) {
    s32 temp_r1;
    s32 var_ip;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg1, void **, 8);
    var_ip = M2C_FIELD(arg1, s32 *, 0);
    temp_r1 = M2C_FIELD(temp_r0, u16 *, 4) << 0xC;
    if (var_ip >= temp_r1) {
        var_ip = temp_r1 - 1;
    } else if (var_ip < 0) {
        var_ip = 0;
    }
    func_020f9b5c(temp_r0, arg2, var_ip, arg0);
}
