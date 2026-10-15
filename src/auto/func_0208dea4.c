/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0211fdd4;

s32 func_0208dea4(u32 arg0) {
    if (arg0 < 6U) {
        return *((M2C_UNK *) ((s8 *) &data_0211fdd4 + ((arg0 + 0x5A) * 4)));
    }
    return M2C_FIELD(&data_0211fdd4, s32 *, 0x168);
}
