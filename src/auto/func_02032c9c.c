/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd504(s16);                         /* extern */
M2C_UNK func_02032448();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern void *data_027e000c;

void func_02032c9c(void) {
    func_020559cc(data_027e000c, 1);
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) + 1);
    func_02032448();
    M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) + 0x55);
    func_01ffd504((s16) (0x800 - (M2C_FIELD(data_027e000c, u8 *, 0xA2) * 0x55)));
    if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0x18) {
        M2C_FIELD(data_027e000c, s8 *, 0x91)   = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x92)   = 2;
        M2C_FIELD(data_027e000c, s8 *, 0x93)   = 0;
        M2C_FIELD(data_027e000c, s16 *, 0x186) = 0x23;
        M2C_FIELD(data_027e000c, s16 *, 0x18C) = 1;
    }
}
