#include "engine.h"
#include "m2c.h"

extern u8 data_02136ea0;
extern M2C_UNK data_02136eb0;
extern M2C_UNK data_02136eb4;

s32 func_02004be0(void) {
    s32 temp_r0;

    if ((u32) M2C_FIELD(&data_02136eb0, u8 *, 0x1A4) <= (u32) data_02136ea0) {
        return 0;
    }
    temp_r0 = (data_02136ea0 * 0x34) + (s32) &data_02136eb4;
    data_02136ea0 += 1;
    return temp_r0;
}
