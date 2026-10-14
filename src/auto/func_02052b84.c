/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;

void func_02052b84(void) {
    s32 temp_r0;
    s32 var_r3;

    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    M2C_FIELD(data_027e000c, s16 *, 0x42) = 0;
    func_020559cc(data_027e000c, 4);
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) {
        var_r3 = 0xC8;
        M2C_FIELD(data_027e000c, s16 *, 0x194) = 0xA;
    } else {
        var_r3 = 0x12C;
        M2C_FIELD(data_027e000c, s16 *, 0x194) = 0x12;
    }
    temp_r0 = M2C_FIELD(data_027e000c, s32 *, 0x30);
    func_02052114(temp_r0, M2C_FIELD(data_027e000c, s32 *, 0x38), temp_r0, M2C_FIELD(data_027e000c, s32 *, 0xB8) - var_r3, (s32) M2C_FIELD(data_027e000c, s16 *, 0x194));
}
