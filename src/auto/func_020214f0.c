/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, s16);              /* extern */
s16 func_01ffd2c4(M2C_UNK *, s16);                  /* extern */
s32 func_0201e904(void *, M2C_UNK);                 /* extern */
M2C_UNK func_0201ea18(void *, s16);                 /* extern */
M2C_UNK func_0201eaa4(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_027e0054;

void *func_020214f0(void *arg0) {
    s16 var_r4;
    s32 var_r0;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    u8 temp_r1;

    func_0201eaa4(arg0, 0x14, 0xF0);
    M2C_FIELD(&data_027e0054, volatile s32 *, 0) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x176);
    M2C_FIELD(&data_027e0054, volatile s32 *, 4) = 0;
    M2C_FIELD(&data_027e0054, volatile s32 *, 8) = (s32) M2C_FIELD(arg0, volatile s16 *, 0x178);
    if ((M2C_FIELD(arg0, volatile s16 *, 0x19A) == 0) && ((s32) M2C_FIELD(arg0, volatile s16 *, 0x190) < 0xA) &&
        ((s32) M2C_FIELD(arg0, volatile s16 *, 0xA6) >= 0xF0)) {
        var_r4 = func_01ffd2c4(&data_027e0054, M2C_FIELD(arg0, volatile s16 *, 0x180));
        func_01ffd214(&data_027e0054, M2C_FIELD(arg0, volatile s16 *, 0x180));
    } else {
        if (M2C_FIELD(arg0, volatile u16 *, 0x188) & 0x11) {
            if (M2C_FIELD(arg0, volatile u16 *, 0x198) & 1) {
                var_r2 = 0;
            } else {
                var_r2 = 0x20;
            }
            M2C_FIELD(arg0, volatile s16 *, 0x186) =
                func_01ffd2c4(&data_027e0054, (s16) (M2C_FIELD(arg0, volatile s16 *, 0x180) + var_r2));
            M2C_FIELD(arg0, volatile u16 *, 0x198) = (u16) (M2C_FIELD(arg0, volatile u16 *, 0x198) & ~1);
        }
        var_r4                                 = M2C_FIELD(arg0, volatile s16 *, 0x186);
        M2C_FIELD(arg0, volatile s16 *, 0x44)  = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x44) + var_r4);
        M2C_FIELD(arg0, volatile s16 *, 0x190) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x190) - 1);
        if ((s32) M2C_FIELD(arg0, volatile s16 *, 0x190) <= 0xA) {
            M2C_FIELD(arg0, volatile s16 *, 0x190) = 5;
            M2C_FIELD(arg0, volatile u16 *, 0x198) = (u16) (M2C_FIELD(arg0, volatile u16 *, 0x198) & ~1);
        }
    }
    temp_r1 = M2C_FIELD(arg0, volatile u8 *, 0x18A);
    if (!(temp_r1 & 2)) {
        if (!(temp_r1 & 1)) {
            M2C_FIELD(arg0, volatile s16 *, 0x18E) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x18E) + 1);
            if (M2C_FIELD(arg0, volatile s16 *, 0x18E) == 6) {
                M2C_FIELD(arg0, volatile s8 *, 0x91)   = 0;
                M2C_FIELD(arg0, volatile s8 *, 0xA)    = 0xC;
                M2C_FIELD(arg0, volatile u16 *, 0x196) = (u16) (M2C_FIELD(arg0, volatile u16 *, 0x196) | 4);
                return arg0 + 0x100;
            }
            goto block_16;
        }
        M2C_FIELD(arg0, volatile s16 *, 0x18E) = 0;
        M2C_FIELD(arg0, volatile s16 *, 0xA6)  = 0xF0;
        M2C_FIELD(arg0, volatile s16 *, 0x176) = (s16) M2C_FIELD(&data_02143cc0, volatile s32 *, 0xF74);
        M2C_FIELD(arg0, volatile s16 *, 0x178) = (s16) M2C_FIELD(&data_02143cc0, volatile s32 *, 0xF7C);
        goto block_16;
    }
block_16:
    func_0201ea18(arg0, var_r4);
    if (!(M2C_FIELD(arg0, volatile u16 *, 0x196) & 2)) {
        if (M2C_FIELD(arg0, volatile u16 *, 0x188) & 0x11) {
            M2C_FIELD(arg0, volatile s16 *, 0x18C) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x18C) + 2);
            if ((s32) M2C_FIELD(arg0, volatile s16 *, 0x18C) > 0xF) {
                M2C_FIELD(arg0, volatile s8 *, 0x91)   = 0;
                M2C_FIELD(arg0, volatile s8 *, 0xA)    = 9;
                M2C_FIELD(arg0, volatile s16 *, 0x182) = (s16) (var_r4 * 2);
                M2C_FIELD(arg0, volatile u16 *, 0x198) = (u16) (M2C_FIELD(arg0, volatile u16 *, 0x198) & ~0x80);
            }
        } else {
            if ((s32) M2C_FIELD(arg0, volatile s16 *, 0x18C) > 0) {
                var_r2_2 = 1;
            } else {
                var_r2_2 = 0;
            }
            M2C_FIELD(arg0, volatile s16 *, 0x18C) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x18C) - var_r2_2);
        }
    } else {
        if ((func_0201e904(arg0, 4) != 0) && (M2C_FIELD(arg0, volatile s16 *, 0x19A) == 0)) {
            M2C_FIELD(arg0, volatile s8 *, 0x92) = 1;
            M2C_FIELD(arg0, volatile s8 *, 0x93) = 0;
        }
        if ((s32) M2C_FIELD(arg0, volatile s16 *, 0x19A) > 0) {
            var_r2_3 = 1;
        } else {
            var_r2_3 = 0;
        }
        M2C_FIELD(arg0, volatile s16 *, 0x19A) = (s16) (M2C_FIELD(arg0, volatile s16 *, 0x19A) - var_r2_3);
    }
    var_r0 = M2C_FIELD(arg0, volatile u16 *, 0x198) & 0xC;
    if (var_r0 != 0) {
        M2C_FIELD(arg0, volatile s8 *, 0x92) = 2;
        var_r0                               = 0;
        M2C_FIELD(arg0, volatile s8 *, 0x92) = 0;
    }
    return (void *) var_r0;
}
