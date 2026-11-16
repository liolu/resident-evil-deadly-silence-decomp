/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Fn)(void);
s32 func_02092a2c(void);
void func_02092ab0(void);
extern u8 data_02120224[];
extern Fn data_02120238[];
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213e394;

s32 func_02092b2c(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if ((var_r0 != 0) || (M2C_FIELD(&data_0213ad98, u8 *, 5) == 0x7E)) {
        M2C_FIELD(&data_0213e394, u8 *, 5) = data_02120224[M2C_FIELD(&data_0213b2b4, u8 *, 1)];
        data_02120238[M2C_FIELD(&data_0213e394, u8 *, 1)]();
        if (M2C_FIELD(&data_0213e394, u8 *, 4) != 0) {
            func_02092ab0();
        }
        var_r0 = func_02092a2c();
    }
    return var_r0;
}
