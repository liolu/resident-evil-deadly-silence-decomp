/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_02127018;
extern M2C_UNK data_02127020;
extern M2C_UNK data_0212f9dc;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *, s32);
extern M2C_UNK data_02141cc0;

void func_020d880c(s32 arg0) {
    if (data_0213ad20 != NULL) {
        data_0213ad20(&data_02127018, *((M2C_UNK *) ((s8 *) &data_0212f9dc + (M2C_FIELD(&data_02141cc0, s32 *, 0x40) * 4))));
    }
    M2C_FIELD(&data_02141cc0, s32 *, 0x40) = arg0;
    if (data_0213ad20 != NULL) {
        data_0213ad20(&data_02127020, *((M2C_UNK *) ((s8 *) &data_0212f9dc + (arg0 * 4))));
    }
}
