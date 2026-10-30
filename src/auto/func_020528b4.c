/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020520c0();                            /* extern */
M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern void *data_027e000c;

void func_020528b4(void) {
    s32 temp_r1;

    func_020520c0();
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x92) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x92) + 1);
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        func_020559cc(data_027e000c, 5);
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = 4;
        temp_r1                               = M2C_FIELD(data_027e000c, s32 *, 0x38);
        func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), temp_r1, M2C_FIELD(data_027e000c, s32 *, 0xB0) - 0x64, temp_r1,
                      (s32) M2C_FIELD(data_027e000c, s16 *, 0xA8));
    }
}
