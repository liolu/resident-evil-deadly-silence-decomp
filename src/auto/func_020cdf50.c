/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02076e50(s32);                         /* extern */
M2C_UNK func_0209ffcc(s32);                         /* extern */
extern M2C_UNK data_0213b890;

void func_020cdf50(void) {
    u32 var_r6;

    func_0209ffcc(M2C_FIELD(&data_0213b890, s32 *, 0x258));
    var_r6 = 0;
    do {
        func_02076e50((var_r6 * 0x3C) + M2C_FIELD(&data_0213b890, s32 *, 0x4C));
        var_r6 += 1;
    } while (var_r6 < 5U);
}
