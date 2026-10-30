/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_0200d470();                            /* extern */
extern M2C_UNK data_0213abc4;

void func_020b778c(void) {
    s32 temp_r3;
    u32 var_ip;

    func_0200d470();
    var_ip = 0;
    do {
        temp_r3                        = (var_ip * 0xC) + (s32) &data_0213abc4;
        M2C_FIELD(temp_r3, s8 *, 0xE4) = 4;
        var_ip += 1;
        M2C_FIELD(temp_r3, s8 *, 0xE5) = 4;
    } while (var_ip < 4U);
}
