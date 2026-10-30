/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_020d9650();                                /* extern */
extern s32 data_027e0018;
extern M2C_UNK data_027e0054;

void func_0201c8ec(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xA8)        = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) + 1);
    M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 0x176);
    M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x178);
    M2C_FIELD(&data_027e0054, s32 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 0x44)        = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + func_01ffd2c4(&data_027e0054, 4));
    if ((func_020d9650() & 1) && ((s32) data_027e0018 < 0x2328)) {
        M2C_FIELD(arg0, u8 *, 0xA) = (u8) (M2C_FIELD(arg0, u8 *, 0xA) - 1);
        if (M2C_FIELD(arg0, u8 *, 0xA) == 7) {
            M2C_FIELD(arg0, u8 *, 0xA) = 4U;
        }
        return;
    }
    if ((M2C_FIELD(arg0, u8 *, 0x92) != 0) || ((s32) data_027e0018 < 0xBB8)) {
        M2C_FIELD(arg0, u8 *, 0xA) = (u8) (M2C_FIELD(arg0, u8 *, 0xA) - 1);
        if (M2C_FIELD(arg0, u8 *, 0xA) == 7) {
            M2C_FIELD(arg0, u8 *, 0xA) = 4U;
        }
    }
}
