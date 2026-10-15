/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;
extern u16 data_0213ad30;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_02144cc0;

s32 func_02087e74(void) {
    if (M2C_FIELD(&data_021375ac, s8 *, 0xE) != 0) {
        return 4;
    }
    if ((M2C_FIELD(&data_021375ac, s8 *, 0x62) != 0) && (((s32) M2C_FIELD(&data_021375ac, s32 *, 0x40) <= 0) ||
                                                         (data_0213ad30 != 0) || (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0))) {
        return 4;
    }
    if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x17A) != 0) {
        return 1;
    }
    if (((s32) M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5B0) >=
         (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x59C), u16 *, 6)) &&
        (M2C_FIELD(&data_02144cc0, u8 *, 0xE5) == 0)) {
        return 2;
    }
    if (((u32) (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5B2) << 0x1F) >> 0x1F) != 0) {
        return 3;
    }
    return 0;
}
