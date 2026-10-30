/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
s16 func_0201df30(s32, s32);                        /* extern */
s32 func_0203d1d0(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020abd88(M2C_UNK);                     /* extern */
M2C_UNK func_020ad71c(u8, M2C_UNK);                 /* extern */
s32 func_020ad804();                                /* extern */
M2C_UNK func_020b8110(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020d9818(M2C_UNK *);                       /* extern */
extern u8 data_0213ad98;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;
extern M2C_UNK data_02144c34;
extern s32 data_027e0004;
extern void *data_027e000c;

void func_0203afa4(void) {
    s32 temp_r0_2;
    u8 temp_r0;
    u8 temp_r1;
    void *temp_r4;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, u8 *, 0xA2) = 0U;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            func_020559cc(data_027e000c, 0xA);
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 3;
            func_020b8110(0x50, 0);
        /* fallthrough */
        case 1:
            temp_r4 = data_027e000c;
            if (M2C_FIELD(temp_r4, u8 *, 0xA) != 5) {
                M2C_FIELD(temp_r4, s16 *, 0x44) =
                    (s16) (((M2C_FIELD(temp_r4, s16 *, 0x17E) & 1) * func_01ffd2c4(&data_02144c34, 0x20)) +
                           M2C_FIELD(temp_r4, s16 *, 0x44));
            }
            if (func_0209109c(0, 0x400, 2) != 0) {
                M2C_FIELD(data_027e000c, u8 *, 0x93) = 2U;
            }
            temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
            if ((temp_r0 == 0x11) || (temp_r0 == 0x15)) {
                if (M2C_FIELD(data_027e000c, u8 *, 0xA) == 5) {
                    func_020b8110(0x4F, 0);
                } else if (data_0213ad98 == 4) {
                    func_020b8110(0x51, 0);
                } else {
                    func_020b8110(0xCC, 0);
                }
            }
            if ((M2C_FIELD(data_027e000c, u8 *, 0xA) == 5) && (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 1)) {
                func_020b8110(0x55, 0);
            }
            func_01ffd504(0);
            if ((M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0xA) && (func_0203d1d0(0x200, 0x7D0) != 0) &&
                (func_020d9818(&data_02144c04) != 0)) {
                M2C_FIELD(data_027e000c, u8 *, 0xC0) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xC0) & 8);
                if (M2C_FIELD(data_027e000c, u8 *, 0xC0) == 0) {
                    M2C_FIELD(data_027e000c, s8 *, 0x92) = 4;
                    M2C_FIELD(data_027e000c, u8 *, 0x93) = 0U;
                    M2C_FIELD(data_027e000c, s16 *, 0x44) =
                        func_0201df30(M2C_FIELD(&data_02143cc0, s32 *, 0xF74), M2C_FIELD(&data_02143cc0, s32 *, 0xF7C));
                    M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 1;
                    M2C_FIELD(data_027e000c, s8 *, 0x96)   = 1;
                    return;
                }
            }
            if ((M2C_FIELD(data_027e000c, s16 *, 0x18E) != 0) && (M2C_FIELD(data_027e000c, s16 *, 0x180) != 0) &&
                (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0xA) && (func_020ad804() != 0)) {
                func_020ad71c(M2C_FIELD(data_027e000c, u8 *, 9), 5);
                temp_r0_2                              = func_020d9818(&data_02144c04);
                data_027e0004                          = temp_r0_2;
                M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = (s8) (temp_r0_2 + 1);
                M2C_FIELD(&data_02143cc0, s8 *, 0xFD6) = (s8) (temp_r0_2 + 0x66);
                func_020abd88(0);
                return;
            }
            return;
        case 2:
            if (M2C_FIELD(data_027e000c, u8 *, 0xA) == 5) {
                M2C_FIELD(data_027e000c, s16 *, 0x18E) = 1;
            }
            M2C_FIELD(data_027e000c, u8 *, 0xA)  = 1U;
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 0U;
            break;
    }
}
