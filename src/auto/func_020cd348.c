/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02125f8c;
extern M2C_UNK data_02125f98;
extern M2C_UNK data_02125fbc;
extern M2C_UNK data_0213b890;

s16 func_020cd348(s32 arg0) {
    if ((u32) M2C_FIELD(&data_0213b890, u8 *, 0x1E) < 4U) {
        return *((u16 *) ((s8 *) &data_02125f8c + (arg0 * 2)));
    }
    if ((u32) M2C_FIELD(&data_0213b890, u8 *, 0x1E) < 8U) {
        return *((u16 *) ((s8 *) &data_02125f98 + (arg0 * 2)));
    }
    return *((u16 *) ((s8 *) &data_02125fbc + (arg0 * 2)));
}
