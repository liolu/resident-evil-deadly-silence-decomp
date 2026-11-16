/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020751c4();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02147cc0;

void func_02074f38(void) {
    u32 var_ip;
    u32 var_r3;
    u8 *temp_r2;
    u32 temp_r1;
    u8 temp_r0;

    func_020751c4();
    var_r3  = 0;
    var_ip  = var_r3;
    temp_r2 = (u8 *) M2C_FIELD(&data_02147cc0, s32 *, 0x538);
    temp_r1 = M2C_FIELD(&data_02147cc0, u8 *, 0x540);
    goto cond;
loop:
    temp_r0 = temp_r2[var_ip * 2];
    var_ip += 1;
    if (temp_r0 != 0) {
        var_r3 += 1;
    }
cond:
    if (var_ip < temp_r1) {
        goto loop;
    }
    M2C_FIELD(&data_0213ad98, s8 *, 7) = var_r3;
}
