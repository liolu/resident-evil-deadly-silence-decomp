/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200e530(M2C_UNK *, u16, u16, u16);    /* extern */
M2C_UNK func_0210616c(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK data_021543a4;
extern M2C_UNK data_02154460;
extern M2C_UNK data_027e0124;

void func_020a02d8(void *arg0) {
    func_0200e530(&data_027e0124, (u16) (M2C_FIELD(arg0, s16 *, 0) * 0x10), (u16) ((0 - M2C_FIELD(arg0, s16 *, 2)) * 0x10),
                  (u16) ((0 - M2C_FIELD(arg0, s16 *, 4)) * 0x10));
    func_0210616c(&data_027e0124, &data_02154460);
    M2C_FIELD(&data_021543a4, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_021543a4, s32 *, 0xFC) & ~0xA4);
}
