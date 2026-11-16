/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02106070(u16, s32, M2C_UNK);           /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_027e01ac;

void func_020bedcc(void) {
    volatile u16 sp0;

    sp0 = 0;
    func_02106070(sp0, M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x1A, 0x600);
    M2C_FIELD(&data_027e01ac, s16 *, 0x24) = 0;
    M2C_FIELD(&data_027e01ac, s32 *, 0x2C) = (s32) (M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x1A);
    M2C_FIELD(&data_027e01ac, s16 *, 0x26) = 0x600;
    M2C_FIELD(&data_027e01ac, s8 *, 0x28)  = 1;
}
