#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;

s32 func_020885f0(void) {
    return (s32) M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x4BC);
}
