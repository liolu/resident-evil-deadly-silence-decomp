/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213cfe4;
extern M2C_UNK data_0213d000;

s32 func_020d8e0c(s32 arg0) {
    if (*((M2C_UNK *) ((s8 *) &data_0213cfe4 + (arg0 * 4))) != 0) {
        return (0x60 * arg0) + (s32) &data_0213d000;
    }
    return 0;
}
