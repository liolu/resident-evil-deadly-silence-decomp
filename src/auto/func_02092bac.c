/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02092a2c();
M2C_UNK func_02092ab0();
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_0213e394;

s32 func_02092bac(void) {
    s32 var_r0;
    u16 v;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if ((var_r0 != 0) || (M2C_FIELD(&data_0213ad98, u8 *, 5) == 0x7E)) {
        v                                      = (u16) M2C_FIELD(&data_0213daa8, u16 *, 0x74);
        M2C_FIELD(&data_0213e394, s8 *, 4)     = 1;
        M2C_FIELD(&data_0213e394, u16 *, 0x10) = v;
        func_02092ab0();
        var_r0 = func_02092a2c();
    }
    return var_r0;
}
