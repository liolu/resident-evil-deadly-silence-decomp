/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_02024db4(void) {
    if ((s32) data_027e0018 < 0xBB8) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 8;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        return;
    }
    if ((M2C_FIELD(&data_02143cc0, u8 *, 0xFD6) == 0x14) && (M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) == 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 8;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        return;
    }
    if ((s32) data_027e0018 > 0x1388) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 2;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
    if (((s32) data_027e0018 > 0x1388) && (func_01ffd2c4(&data_02144c34, 0x80) == 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 0xB;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
}
