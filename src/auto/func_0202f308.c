/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_0202f19c(s32);                         /* extern */
s32 func_020ad804(void *);                          /* extern */
s32 func_020d9764(M2C_UNK *);                       /* extern */
extern void *data_02137338;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0004;
extern void *data_027e000c;
extern s32 data_027e0018;
extern s32 data_027e0020;

void func_0202f308(void) {
    s32 temp_r1_2;
    s32 var_r0;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r3;
    s32 var_r3_2;
    u8 temp_r1;
    void *temp_r4;

    if (M2C_FIELD(data_027e000c, u8 *, 0xA) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA) = 2U;
        return;
    }
    temp_r4 = M2C_FIELD(data_02137338, void **, 0);
    if ((s32) M2C_FIELD(temp_r4, s16 *, 0x94) < 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA) = 2U;
    }
    var_r3 = M2C_FIELD(temp_r4, s32 *, 0x38) - M2C_FIELD(data_027e000c, s32 *, 0x38);
    if (var_r3 < 0) {
        var_r3 = 0 - var_r3;
    }
    var_r1 = M2C_FIELD(temp_r4, s32 *, 0x30) - M2C_FIELD(data_027e000c, s32 *, 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0020 = var_r1 + var_r3;
    temp_r1       = M2C_FIELD(data_027e000c, u8 *, 0x92);
    data_027e0004 = (s32) temp_r1;
    if (M2C_FIELD(temp_r4, u8 *, 0x96) != 0) {
        if (temp_r1 != 2) {
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        }
        M2C_FIELD(data_027e000c, u8 *, 0x92) = 2U;
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    }
    if ((M2C_FIELD(data_02137338, s16 *, 6) != 0) && ((s32) data_027e0018 < 0xFA0)) {
        if (data_027e0004 != 2) {
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        }
        M2C_FIELD(data_027e000c, u8 *, 0x92) = 2U;
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    }
    var_r0 = M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) & 0x80;
    if (var_r0 != 0) {
        var_r0 = 0xBB8;
        if ((s32) data_027e0018 < 0xBB8) {
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, u8 *, 0x92) = 9U;
            var_r0                               = (s32) data_027e000c;
            M2C_FIELD(var_r0, s8 *, 0x93)        = 0;
        }
    }
    if (func_020ad804((void *) var_r0) != 0) {
        if ((func_020d9764(&data_02144c34) == 0) && ((s32) data_027e0018 < 0xBB8) &&
            (func_01ffd2c4(&data_02144c34, 0x80) == 0)) {
            M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
            M2C_FIELD(data_027e000c, u8 *, 0x92) = 4U;
            M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        }
        if ((M2C_FIELD(data_02137338, s16 *, 6) != 0) && ((M2C_FIELD(data_027e000c, u8 *, 0xA) & 0xF) != 7)) {
            if (((s32) data_027e0018 > (s32) data_027e0020) && (func_01ffd2c4(&data_02144c34, 0x20) == 0) &&
                ((s32) data_027e0020 < 0xFA0) && (func_01ffd2c4(temp_r4 + 0x30, 0x200) == 0) &&
                ((s32) M2C_FIELD(temp_r4, s16 *, 0xA6) < 0x32)) {
                M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
                M2C_FIELD(data_027e000c, u8 *, 0x92) = 6U;
                M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
                M2C_FIELD(data_027e000c, u8 *, 8)    = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
            }
            if ((func_01ffd2c4(temp_r4 + 0x30, 0x200) == 0) && (M2C_FIELD(data_02137338, u8 *, 0x12) != 0) &&
                ((s32) data_027e0020 < 0xBB8)) {
                M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
                M2C_FIELD(data_027e000c, u8 *, 0x92) = 6U;
                M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
                M2C_FIELD(data_027e000c, u8 *, 8)    = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
            }
        }
        var_r3_2 = M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) - M2C_FIELD(data_027e000c, s32 *, 0x38);
        if (var_r3_2 < 0) {
            var_r3_2 = 0 - var_r3_2;
        }
        var_r1_2 = M2C_FIELD(&data_02143cc0, s32 *, 0xF74) - M2C_FIELD(data_027e000c, s32 *, 0x30);
        if (var_r1_2 < 0) {
            var_r1_2 = 0 - var_r1_2;
        }
        temp_r1_2     = var_r1_2 + var_r3_2;
        data_027e0018 = temp_r1_2;
        if ((temp_r1_2 < 0x7D0) && (func_01ffd2c4(&data_02144c34, 0x100) == 0) &&
            (M2C_FIELD(data_02137338, u8 *, 0x14) != 0)) {
            func_0202f19c(M2C_FIELD(&data_0213ad98, u16 *, 0x1A) & 1);
        }
    }
}
