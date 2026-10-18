#include "m2c.h"

extern M2C_UNK data_0213ae60;

s8 func_020133c0(s32 arg0) {
    return *((u8 *) ((s8 *) &data_0213ae60 + (arg0 * 0xC)));
}
