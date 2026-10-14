/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020f49c8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021543a4;
extern M2C_UNK data_021543ac;
extern M2C_UNK data_02154564;

s32 func_020f4978(void) {
    if (!(M2C_FIELD(&data_021543a4, s32 *, 0xFC) & 0x10)) {
        func_020f49c8((s32) &data_021543ac, (s32) &data_02154564);
        M2C_FIELD(&data_021543a4, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_021543a4, s32 *, 0xFC) | 0x10);
    }
    return (s32) &data_02154564;
}
