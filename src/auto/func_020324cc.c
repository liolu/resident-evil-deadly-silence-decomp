/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_02032448();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern void *data_027e000c;

void func_020324cc(void) {
    s32 temp_r1;

    func_020559cc(data_027e000c, 2);
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) + 1);
    func_02032448();
    M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) + 0x14);
    temp_r1                               = M2C_FIELD(data_027e000c, s32 *, 0x34);
    if (temp_r1 > -0xAF0) {
        M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (temp_r1 + 0x14);
        func_01ffd504(0);
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) + 1);
        if ((s32) M2C_FIELD(data_027e000c, s16 *, 0xA8) > 0x14) {
            M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) - 0x3C);
        }
    }
    if ((s32) M2C_FIELD(data_027e000c, s16 *, 0xA8) > 0x19) {
        M2C_FIELD(data_027e000c, u8 *, 8)      = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0xFD);
        M2C_FIELD(data_027e000c, s8 *, 0x96)   = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x91)   = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x92)   = 2;
        M2C_FIELD(data_027e000c, s8 *, 0x93)   = 0;
        M2C_FIELD(data_027e000c, s16 *, 0x186) = 0x23;
        M2C_FIELD(data_027e000c, s16 *, 0x18C) = 1;
    }
}
