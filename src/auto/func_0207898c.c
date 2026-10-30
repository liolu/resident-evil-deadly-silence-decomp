/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0207897c(u8);                              /* extern */
extern M2C_UNK data_0213b890;

s32 func_0207898c(s32 arg0, s32 arg1) {
    if (arg0 != func_0207897c(M2C_FIELD(&data_0213b890, u8 *, 0x92))) {
        return 0;
    }
    if (arg1 == M2C_FIELD(&data_0213b890, u8 *, 0x93)) {
        return 1;
    }
    return 0;
}
