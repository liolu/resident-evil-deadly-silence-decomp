/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_0203c704();                            /* extern */
M2C_UNK func_02074ad4(s16, s16, void *, void *);    /* extern */
M2C_UNK func_020b8110(u16, M2C_UNK);                /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0000;
extern void *data_027e000c;
extern M2C_UNK data_027e0054;

void func_0203c820(void) {
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    void *temp_r4;

    temp_r4 = data_027e000c;
    if (M2C_FIELD(temp_r4, s16 *, 0x17E) & 1) {
        func_02074ad4((s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74), (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C),
                      temp_r4 + 0x176, temp_r4 + 0x178);
        M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(data_027e000c, s16 *, 0x176);
        M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(data_027e000c, s16 *, 0x178);
        M2C_FIELD(&data_027e0054, s32 *, 4) = 0;
        func_01ffd214(&data_027e0054, 0x40);
    } else {
        M2C_FIELD(temp_r4, s16 *, 0x44) =
            (s16) (((M2C_FIELD(temp_r4, s16 *, 0x17E) & 1) * func_01ffd2c4(&data_02144c34, 0x10)) +
                   M2C_FIELD(temp_r4, s16 *, 0x44));
    }
    func_0203c704();
    func_01ffd504(0);
    data_027e0000 = 0x4F;
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 2) &&
        ((temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0 == 1)) || (temp_r0 == 7))) {
        func_020b8110(0x4FU, 0);
    }
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 3) &&
        ((temp_r0_2 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0_2 == 1)) || (temp_r0_2 == 0xC))) {
        func_020b8110((u16) data_027e0000, 0);
    }
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 9) &&
        ((temp_r0_3 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0_3 == 1)) || (temp_r0_3 == 0xF))) {
        func_020b8110((u16) data_027e0000, 0);
    }
}
