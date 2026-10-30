/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02000d40(M2C_UNK, s16, s16);               /* extern */
M2C_UNK func_020153a4(void *);                      /* extern */
extern M2C_UNK data_02143cc0;

void func_020158dc(void *arg0) {
    s32 temp_r1;

    M2C_FIELD(arg0, u8 *, 4) = (u8) (M2C_FIELD(arg0, u8 *, 4) - 1);
    if (M2C_FIELD(arg0, u8 *, 4) == 0) {
        M2C_FIELD(arg0, u8 *, 4)       = 4U;
        M2C_FIELD(arg0, void **, 0x90) = (void *) (M2C_FIELD(arg0, s32 *, 0x8C) + 0x1C);
        M2C_FIELD(arg0, u8 *, 0x1F)    = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x90), u8 *, 0);
        M2C_FIELD(arg0, u8 *, 0x1E)    = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x90), u8 *, 1);
        M2C_FIELD(arg0, s32 *, 0x98)   = (s32) (M2C_FIELD(arg0, s32 *, 0x94) + (M2C_FIELD(arg0, u8 *, 0x1F) * 4));
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12);
    if (temp_r1 >= -0x960) {
        if (temp_r1 >= 0) {
            func_020153a4(arg0);
            M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(arg0, u16 *, 0xE) | 0x4007);
        }
        if ((M2C_FIELD(&data_02143cc0, u8 *, 0xFD4) == 1) &&
            (func_02000d40(0x384, M2C_FIELD(arg0, s16 *, 0x20), M2C_FIELD(arg0, s16 *, 0x24)) != 0)) {
            func_020153a4(arg0);
        }
    }
}
