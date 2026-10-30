/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020935d4(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_0213bb18;

void func_02093654(void *arg0) {
    if ((((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x11) >> 0x1F) != 0) &&
        ((u32) M2C_FIELD(arg0, u16 *, 0x172) < 0x80U)) {
        M2C_FIELD(arg0, u8 *, 0x169) = (u8) (M2C_FIELD(arg0, u8 *, 0x169) | 1);
        func_020935d4(arg0, 0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x50) = 0x7FFF;
}
