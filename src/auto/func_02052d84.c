/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;

void func_02052d84(void) {
    u8 temp_r0;

    M2C_FIELD(data_027e000c, s32 *, 0x188) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x188) + M2C_FIELD(data_027e000c, s32 *, 0x17C));
    M2C_FIELD(data_027e000c, s32 *, 0x190) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x190) + M2C_FIELD(data_027e000c, s32 *, 0x184));
    M2C_FIELD(data_027e000c, s32 *, 0x30) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x188) >> 0x10);
    M2C_FIELD(data_027e000c, s32 *, 0x38) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x190) >> 0x10);
    if (func_02075738(1, 0x200) != 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x20);
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) {
        temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
        if ((temp_r0 == 3) || (temp_r0 == 0xD)) {
            func_020b82fc(0x80);
        }
    } else if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 8) {
        func_020b82fc(0x80);
    }
}
