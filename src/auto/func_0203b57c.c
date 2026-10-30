/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_0203c704();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b8110(u16, M2C_UNK);                /* extern */
extern M2C_UNK data_02144c34;
extern s32 data_027e0000;
extern void *data_027e000c;

void func_0203b57c(void) {
    u8 temp_r0;
    u8 temp_r0_2;
    void *temp_r4;

    if (M2C_FIELD(data_027e000c, s16 *, 0x18A) != 0) {
        func_020559cc(data_027e000c, 2);
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0xC8;
    } else {
        func_020559cc(data_027e000c, 3);
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0x64;
    }
    M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) + 0x800);
    temp_r4                               = data_027e000c;
    M2C_FIELD(temp_r4, s16 *, 0x44) = (s16) (((M2C_FIELD(temp_r4, s16 *, 0x17E) & 1) * func_01ffd2c4(&data_02144c34, 0x10)) +
                                             M2C_FIELD(temp_r4, s16 *, 0x44));
    M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) - 0x800);
    func_0203c704();
    func_01ffd504(0x800);
    data_027e0000 = 0x4F;
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 2) &&
        ((temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0 == 1)) || (temp_r0 == 7))) {
        func_020b8110(0x4FU, 0);
    }
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 3) &&
        ((temp_r0_2 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0_2 == 1)) || (temp_r0_2 == 0xC))) {
        func_020b8110((u16) data_027e0000, 0);
    }
}
