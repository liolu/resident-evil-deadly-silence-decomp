#include "m2c.h"

extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02144cc0;

s32 func_020a2ba4(void *arg0) {
    M2C_FIELD(&data_02144cc0, void **, 0xDC) = arg0;
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        return 1;
    }
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x800);
    return 0;
}
