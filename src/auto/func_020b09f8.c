/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020045d0(M2C_UNK, u8);
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b890;

void func_020b09f8(void) {
    s32 var_r4;
    u8 t;

    var_r4 = M2C_FIELD(&data_0213b890, u8 *, 0x1E);
    if (func_020045d0(0, (u8) var_r4) == 0) {
        var_r4 = 0;
    } else {
        t      = M2C_FIELD(((var_r4 * 0x2C0) + M2C_FIELD(&data_0213b890, s32 *, 0x4C)), u8 *, 0x2B9);
        var_r4 = var_r4 | 0x80;
        M2C_FIELD(&data_0213ad48, u8 *, 1) = (u8) ((u32) (t << 0x1C) >> 0x1C);
    }
    M2C_FIELD(&data_0213ad48, u8 *, 0) = (u8) var_r4;
}
