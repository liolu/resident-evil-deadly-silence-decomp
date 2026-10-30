/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0205126c(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;

void func_02051460(void) {
    s32 var_ip;
    s8 var_r2;

    func_02075738(1, 0x200);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) {
            var_r2 = 0;
        } else {
            var_r2 = 0x28;
        }
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = var_r2;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 0x1F;
        if ((M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 3) == 1) {
            func_020559cc(data_027e000c, 4);
        } else {
            func_020559cc(data_027e000c, 6);
        }
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = 0xC;
        if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1) {
            var_ip = 0x8C;
        } else {
            var_ip = 0x46;
        }
        func_0205126c(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38),
                      M2C_FIELD(data_027e000c, s32 *, 0xB0) - 0x64, M2C_FIELD(data_027e000c, s32 *, 0xB8) + var_ip,
                      (s32) (u16) M2C_FIELD(data_027e000c, s16 *, 0xA8));
    }
}
