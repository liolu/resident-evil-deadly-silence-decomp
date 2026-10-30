/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, s16);                  /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
M2C_UNK func_0201ea80(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_0201eac8(void *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_027e0054;

void func_02020db4(void *arg0) {
    u8 temp_r1;

    if ((u32) (u8) (M2C_FIELD(arg0, u8 *, 0xA) + 0xFA) <= 1U) {
        func_01ffd504(0);
        func_0201ea80(arg0, 0x40, 0xF0);
    }
    if (func_0209109c(0, 0x400, 7) != 0) {
        M2C_FIELD(arg0, u8 *, 8)      = (u8) (M2C_FIELD(arg0, u8 *, 8) & ~4);
        M2C_FIELD(arg0, s8 *, 0x91)   = 0;
        M2C_FIELD(arg0, s8 *, 0x96)   = 0;
        M2C_FIELD(arg0, u16 *, 0x198) = (u16) (M2C_FIELD(arg0, u16 *, 0x198) & ~1);
        if (!(M2C_FIELD(arg0, u16 *, 0x188) & 0x11) || (temp_r1 = M2C_FIELD(arg0, u8 *, 0xA), (temp_r1 == 6)) ||
            (temp_r1 == 7) || (M2C_FIELD(arg0, u16 *, 0x196) & 2)) {
            M2C_FIELD(arg0, u8 *, 0xA) = 4U;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0xA)    = 9U;
        M2C_FIELD(arg0, s16 *, 0x182) = (s16) (func_01ffd2c4(&data_027e0054, M2C_FIELD(arg0, s16 *, 0x180)) * 2);
        if (M2C_FIELD(arg0, s16 *, 0x182) == 0) {
            M2C_FIELD(arg0, s16 *, 0x182) = (s16) (M2C_FIELD(arg0, s16 *, 0x180) * 2 * func_0201eac8(arg0, 1, -1));
        }
    }
}
