/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bdcc;

void func_020d609c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x59) == 0) {
        return;
    }
    if (M2C_FIELD(&data_0213b890, u8 *, 0x52) != 0) {
        M2C_FIELD(&data_0213bdcc, s32 *, 0x48) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) | 0x10000);
        return;
    }
    M2C_FIELD(&data_0213bdcc, s32 *, 0x48) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) | 0x40000);
}
