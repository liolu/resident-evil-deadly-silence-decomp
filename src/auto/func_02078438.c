/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad30;
extern M2C_UNK data_0213b2b4;

s32 func_02078438(void) {
    if ((M2C_FIELD(&data_0213b2b4, u8 *, 9) == 0) && (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x30C) && (M2C_FIELD(&data_0213ad30, u16 *, 0) == 0x30C)) {
        return 1;
    }
    return 0;
}
