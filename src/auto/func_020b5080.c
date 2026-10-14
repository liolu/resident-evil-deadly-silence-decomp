/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

void func_020b5080(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_0213daa8, s8 *, 0x23C) = (s8) arg0;
    M2C_FIELD(&data_0213daa8, s8 *, 0x23D) = (s8) arg1;
    M2C_FIELD(&data_0213daa8, s8 *, 0x23E) = (s8) arg2;
    M2C_FIELD(&data_0213daa8, s8 *, 0x23F) = (s8) arg3;
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) == 0) {
        M2C_FIELD(&data_0213daa8, s8 *, 0x245) = 1;
        M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) = 1U;
    }
}
