/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
extern void *data_02137370;
extern M2C_UNK data_02144c34;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_02046b0c(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_02137370, u8 *, 0x13);
    if (temp_r0 != 0) {
        M2C_FIELD(data_02137370, u8 *, 0x13) = (u8) (temp_r0 - 1);
    }
    M2C_FIELD(data_02137370, s8 *, 0x15) = 0;
    if (M2C_FIELD(data_02137370, u8 *, 0x13) == 0) {
        if (((s32) data_027e0018 < 0xA8C) && (func_01ffd2c4(&data_02144c34, 0x340) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 4;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        if ((M2C_FIELD(data_02137370, u8 *, 0x17) != 0) && ((s32) data_027e0018 < 0xA8C) &&
            (func_01ffd2c4(&data_02144c34, 0x340) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 4;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
            M2C_FIELD(data_02137370, u8 *, 2)    = (u8) (M2C_FIELD(data_02137370, u8 *, 2) | 0x80);
            return;
        }
        if (((s32) data_027e0018 < 0x7D0) && (func_01ffd2c4(&data_02144c34, 0x200) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 3;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
    }
}
