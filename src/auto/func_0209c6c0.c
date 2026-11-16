/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213d1a0;

s32 func_0209c6c0(s32 arg0) {
    s32 var_ip;

    var_ip = M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) + arg0;
    while (var_ip < 4 && var_ip > 0) {
        if (M2C_FIELD(&data_0213d1a0, u16 *, 0x18) & (1 << var_ip)) {
            return var_ip;
        }
        var_ip += arg0;
    }
    return -1;
}
