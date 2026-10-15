/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;

s32 func_0204dc74(s32 arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xA) & 1) {
        return 0;
    }
    if ((M2C_FIELD(&data_0213ad98, u8 *, 0) != 1) || (M2C_FIELD(&data_0213ad98, u8 *, 1) != 0x10) ||
        (M2C_FIELD(&data_0213ad98, u8 *, 2) != 5)) {
        return 0;
    }
    if ((u32) (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF) + 0xFF) > 1U) {
        return 1;
    }
    return 0;
}
