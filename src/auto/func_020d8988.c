/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213caa0;

void func_020d8988(void) {
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x55F) == 1) {
        M2C_FIELD(&data_0213caa0, s32 *, 0x554) = 0;
        M2C_FIELD(&data_0213caa0, s8 *, 0x701) = 1;
    }
}
