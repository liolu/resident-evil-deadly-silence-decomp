/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, s32);                  /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern void *data_02137370;
extern M2C_UNK data_0213be18;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_020467dc(void) {
    u8 temp_r0;
    u8 temp_r0_2;

    temp_r0 = M2C_FIELD(data_02137370, u8 *, 0x13);
    if (temp_r0 != 0) {
        M2C_FIELD(data_02137370, u8 *, 0x13) = (u8) (temp_r0 - 1);
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) == 0xA) {
        M2C_FIELD(data_02137370, u8 *, 0x14) = (u8) (M2C_FIELD(data_02137370, u8 *, 0x14) | 0x80);
    }
    temp_r0_2 = M2C_FIELD(data_02137370, u8 *, 0x15);
    if (temp_r0_2 != 0) {
        M2C_FIELD(data_02137370, u8 *, 0x15) = (u8) (temp_r0_2 - 1);
    }
    if (M2C_FIELD(data_02137370, u8 *, 0x13) == 0) {
        if (((s32) data_027e0018 > 0x2EE0) && (func_01ffd2c4(&data_02144c34, 0x40) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 8;
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
        if (((s32) data_027e0018 < 0xA8C) && (func_01ffd2c4(&data_02144c34, 0x340) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 4;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        if (((s32) data_027e0018 < 0x7D0) && (func_01ffd2c4(&data_02144c34, 0x200) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 3;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        if (((s32) data_027e0018 < 0x1B58) && (func_01ffd2c4(&data_02144c34, 0x4C8) != 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 5;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        if (M2C_FIELD(data_02137370, u8 *, 0x15) == 0) {
            M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 0xB;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        goto block_25;
    }
block_25:
    if ((func_020b39e4(&data_0213be18, 0x1E) != 0) && ((s32) data_027e0018 < 0xA8C) &&
        (func_01ffd2c4(&data_02144c34, 0x200) == 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 7;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
}
