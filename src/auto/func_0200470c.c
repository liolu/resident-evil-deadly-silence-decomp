/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02004c3c();

s32 func_0200470c(void *arg0, s32 arg1) {
    u8 *var_ip;
    s32 var_r3;
    s32 var_r0;

    func_02004c3c();
    var_ip = M2C_FIELD(arg0, u8 **, 0x30);
    var_r0 = -1;
    var_r3 = 0;
    goto check;
loop:
    if (M2C_FIELD(var_ip, u8 *, 5) == 2) {
        if (arg1 == M2C_FIELD(var_ip, u8 *, 4)) {
            var_r0 = var_r3;
            goto end;
        }
    }
    var_r3 += 1;
    var_ip += 8;
check:
    if (var_r3 < (s32) M2C_FIELD(arg0, u8 *, 0x1E)) {
        goto loop;
    }
end:
    return var_r0;
}
