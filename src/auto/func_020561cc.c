/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;

s32 func_020561cc(void) {
    if ((M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x10) || (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0)) {
        return 1;
    }
    return 0;
}
