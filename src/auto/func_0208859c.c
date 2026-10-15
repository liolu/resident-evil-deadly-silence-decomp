/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_0208859c(s32 arg0) {
    return (0x1E8 * arg0) + (M2C_FIELD(&data_021375ac, s32 *, 0x64) + 0x5F8);
}
