/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02048144(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0209161c(void *, M2C_UNK);             /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, u8);               /* extern */
extern s8 data_0211cbe4;
extern M2C_UNK data_0213be18;
extern M2C_UNK data_0213db04;
extern void *data_027e000c;

void func_020494bc(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r0) {
        default:
            break;
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93)  = (u8) (temp_r0 + 1);
            M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) - 0xC8);
            M2C_FIELD(data_027e000c, s16 *, 0xA8) = 5;
            func_0209161c(data_027e000c + 0x54, 0);
            M2C_FIELD(data_027e000c, s8 *, 7) = (s8) data_0211cbe4;
            func_02048144(8, 0);
        /* fallthrough */
        case 1:
            M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
            if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
                M2C_FIELD(data_027e000c, s16 *, 0xA8) = 2;
                M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) - 1);
                if ((s32) M2C_FIELD(data_027e000c, s32 *, 0x34) < -1898) {
                    M2C_FIELD(data_027e000c, u8 *, 0x93) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x93) + 1);
                }
            }
            break;
        case 2:
            M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
            if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
                M2C_FIELD(data_027e000c, s16 *, 0xA8) = 2;
                M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) + 1);
                if ((s32) M2C_FIELD(data_027e000c, s32 *, 0x34) > -1748) {
                    M2C_FIELD(data_027e000c, u8 *, 0x93) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x93) - 1);
                }
            }
            break;
        case 3:
            M2C_FIELD(data_027e000c, s32 *, 0x34) = (s32) (M2C_FIELD(data_027e000c, s32 *, 0x34) + 4);
            if ((s32) M2C_FIELD(data_027e000c, s32 *, 0x34) > -1548) {
                func_020b3a24(&data_0213db04, M2C_FIELD(data_027e000c, u8 *, 0xBF));
                M2C_FIELD(data_027e000c, u8 *, 0x93)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x93) + 1);
                M2C_FIELD(data_027e000c, s32 *, 0x34) = -0x60C;
            }
            break;
    }
    if (func_020b39e4(&data_0213be18, 0x1F) != 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x93) = 3U;
    }
}
