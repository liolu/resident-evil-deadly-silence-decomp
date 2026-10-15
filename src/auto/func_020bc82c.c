/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020bb594(M2C_UNK);                     /* extern */
M2C_UNK func_020bb780(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021248e0;
extern void *data_027e000c;
extern s32 data_027e0024;
extern M2C_UNK data_027e0028;

void func_020bc82c(void) {
    func_020bb594(1);
    M2C_FIELD(&data_027e0028, s16 *, 0)  = 0;
    M2C_FIELD(&data_027e0028, s16 *, 2)  = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4)  = -0x50;
    data_027e0024                        = 0x808080;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
    func_020bb780(0, 0x400);
    M2C_FIELD(data_027e000c, M2C_UNK **, 0xC) = &data_021248e0;
}
