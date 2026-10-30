/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_020524c8(void) {
    func_02075738(1, 0x200);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91)   = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        M2C_FIELD(data_027e000c, s16 *, 0xA8)  = 0xC;
        M2C_FIELD(data_027e000c, s32 *, 0x18C) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) << 0x10);
        M2C_FIELD(data_027e000c, s32 *, 0x180) = -0xC0000;
        func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38),
                      M2C_FIELD(data_027e000c, s32 *, 0xB0) - 0x64, M2C_FIELD(data_027e000c, s32 *, 0xB8) - 0x190,
                      (s32) M2C_FIELD(data_027e000c, s16 *, 0xA8));
    }
}
