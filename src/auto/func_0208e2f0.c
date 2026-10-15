/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad3c;

s32 func_0208e2f0(void) {
    s32 var_r0;

    if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x20) {
        if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x4010) {
            var_r0 = 0;
        } else {
            var_r0 = 2;
        }
        return var_r0;
    }
    if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x4010) {
        return 1;
    }
    return 0;
}
