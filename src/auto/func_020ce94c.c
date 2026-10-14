/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

s32 func_020ce94c(void) {
    if ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x143) == 5) && (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x138) == 0)) {
        return 1;
    }
    return 0;
}
