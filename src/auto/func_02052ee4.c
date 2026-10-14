/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020520c0();                            /* extern */
M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_02052ee4(void) {
    s8 var_r2;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x91);
    if (temp_r1 == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (temp_r1 + 1);
        if (M2C_FIELD(data_027e000c, u8 *, 0xA1) == 0) {
            var_r2 = 0;
        } else {
            var_r2 = 7;
        }
        M2C_FIELD(data_027e000c, s8 *, 0x98) = var_r2;
        func_020559cc(data_027e000c, 0);
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = 8;
        func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38), M2C_FIELD(data_027e000c, s32 *, 0xB0), M2C_FIELD(data_027e000c, s32 *, 0xB8), (s32) M2C_FIELD(data_027e000c, s16 *, 0xA8));
    }
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) != 0) {
        func_020520c0();
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    }
    func_02075738(1, 0x200);
}
