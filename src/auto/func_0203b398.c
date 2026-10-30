/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, s16);                  /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020b8110(u16, M2C_UNK);                /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0000;
extern void *data_027e000c;
extern s32 data_027e0024;

void func_0203b398(void) {
    s16 temp_r1;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0xA2)  = 0U;
            M2C_FIELD(data_027e000c, s8 *, 0xA3)  = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98)  = 3;
            M2C_FIELD(data_027e000c, u8 *, 0x93)  = 1U;
            M2C_FIELD(data_027e000c, s16 *, 0xA8) = 0x50;
        /* fallthrough */
        case 1:
            M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) + 0x800);
            data_027e0024                         = func_01ffd2c4(&data_02144c34, M2C_FIELD(data_027e000c, s16 *, 0x17C));
            temp_r1                               = M2C_FIELD(data_027e000c, s16 *, 0xA8);
            M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (temp_r1 - 1);
            if ((temp_r1 == 0) || (data_027e0024 == 0)) {
                M2C_FIELD(data_027e000c, u8 *, 0x93) = 2U;
            }
            func_02075738(1, 0x400);
            data_027e0000 = 0x4F;
            if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 2) &&
                ((temp_r0_2 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0_2 == 1)) || (temp_r0_2 == 7))) {
                func_020b8110(0x4FU, 0);
            }
            if ((M2C_FIELD(data_027e000c, u8 *, 0xA1) == 3) &&
                ((temp_r0_3 = M2C_FIELD(data_027e000c, u8 *, 0xA2), (temp_r0_3 == 1)) || (temp_r0_3 == 0xC))) {
                func_020b8110((u16) data_027e0000, 0);
            }
            M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) + data_027e0024);
            M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) - 0x800);
            return;
        case 2:
            M2C_FIELD(data_027e000c, s8 *, 0x91)   = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x92)   = 0;
            M2C_FIELD(data_027e000c, u8 *, 0x93)   = 0U;
            M2C_FIELD(data_027e000c, s16 *, 0x176) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
            M2C_FIELD(data_027e000c, s16 *, 0x178) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
            return;
    }
}
