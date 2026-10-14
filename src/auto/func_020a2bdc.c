#include "m2c.h"

extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02147cc0;

s32 func_020a2bdc(void *arg0) {
    u8 temp_r2;

    temp_r2 = *M2C_FIELD(&data_02147cc0, u8 **, 0x53C);
    if ((temp_r2 != 0) && (temp_r2 == M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 8))) {
        return 0;
    }
    M2C_FIELD(&data_02144cc0, void **, 0xDC) = arg0;
    return 0;
}
