#include "m2c.h"

extern M2C_UNK data_0211b390;
extern M2C_UNK data_0213b2b4;

u8 func_0200e514(void) {
    return ((s8 *) &data_0211b390)[M2C_FIELD(&data_0213b2b4, u8 *, 1)];
}
