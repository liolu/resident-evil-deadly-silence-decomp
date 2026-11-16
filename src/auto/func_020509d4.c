/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020559cc(void *, u8);
s32 func_020ad9a8();

void func_020509d4(void *arg0) {
    s32 var_r1;

    M2C_FIELD(arg0, u8 *, 8)    = (u8) (M2C_FIELD(arg0, u8 *, 8) | 8);
    M2C_FIELD(arg0, s8 *, 0x91) = 1;
    if (func_020ad9a8() != 0) {
        var_r1 = 0x10;
    } else {
        var_r1 = 0xF;
    }
    func_020559cc(arg0, var_r1);
    M2C_FIELD(arg0, s8 *, 0xA2)   = 0;
    M2C_FIELD(arg0, s8 *, 0xA3)   = 0;
    M2C_FIELD(arg0, s8 *, 0x98)   = 0;
    M2C_FIELD(arg0, s16 *, 0x192) = 0;
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
}
