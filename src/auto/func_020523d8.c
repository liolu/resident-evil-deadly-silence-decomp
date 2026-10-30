/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020520c0();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_020523d8(void) {
    s32 temp_r1;

    func_02075738(1, 0x80);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) != 0) {
        func_020520c0();
        M2C_FIELD(data_027e000c, s32 *, 0x18C) =
            (s32) (M2C_FIELD(data_027e000c, s32 *, 0x18C) + M2C_FIELD(data_027e000c, s32 *, 0x180));
        M2C_FIELD(data_027e000c, s32 *, 0x180) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x180) + 0x28000);
        M2C_FIELD(data_027e000c, s32 *, 0x34)  = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x18C) >> 0x10);
        temp_r1                                = M2C_FIELD(data_027e000c, s32 *, 0xB4);
        if ((s32) M2C_FIELD(data_027e000c, s32 *, 0x34) > temp_r1) {
            M2C_FIELD(data_027e000c, s32 *, 0x34) = temp_r1;
        }
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
        return;
    }
    M2C_FIELD(data_027e000c, u8 *, 0x91)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) M2C_FIELD(data_027e000c, s32 *, 0xB4);
    M2C_FIELD(data_027e000c, s8 *, 0xA2)  = 0xE;
    M2C_FIELD(data_027e000c, s8 *, 0xA3)  = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98)  = 7;
    func_020559cc(data_027e000c, 2);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = 0x5A;
}
