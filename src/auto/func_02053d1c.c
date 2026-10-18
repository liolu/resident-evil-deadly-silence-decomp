/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02144da8;
extern M2C_UNK data_02147cc0;
extern M2C_UNK data_0214813d;

s32 func_02053d1c(void) {
    if (M2C_FIELD(&data_02147cc0, u8 *, 0x47C) == 0) {
        return 0;
    }
    return (*((u8 *) ((s8 *) &data_0214813d + (M2C_FIELD(&data_02147cc0, u8 *, 0x47C) * 4))) * 0x19C) + (s32) &data_02144da8;
}
