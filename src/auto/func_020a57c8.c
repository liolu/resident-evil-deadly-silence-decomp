/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;

s32 func_020a57c8(void) {
    u8 var_r0;

    if (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (s32) var_r0;
}
