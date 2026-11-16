/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02091d4c(M2C_UNK, void *, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0213f2e8;
extern M2C_UNK data_027e01ac;

void func_02072598(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    func_02091d4c(arg3, ((u16 *) &data_0213f2e8) + (arg1 + (arg2 << 5)), 1,
                  (0xFFF & ((0x20 - (arg1 * 2)) * 8)) | ((u8) arg4 << 0xC) | 0x01000000);
    M2C_FIELD(&data_027e01ac, M2C_UNK **, 0x1C) = &data_0213f2e8;
    M2C_FIELD(&data_027e01ac, s16 *, 0x16)      = 0x600;
    M2C_FIELD(&data_027e01ac, s8 *, 0x18)       = 1;
}
