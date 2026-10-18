#include "m2c.h"

extern M2C_UNK data_0213ac6d;

u8 func_020b7c6c(s32 arg0) {
    return *((u8 *) ((s8 *) &data_0213ac6d + (arg0 * 0xC)));
}
