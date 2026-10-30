/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02091d4c(); /* extern */
M2C_UNK func_020b5540();                     /* extern */
M2C_UNK func_020b82fc();                     /* extern */
s32 func_020c0148();                             /* extern */
M2C_UNK func_020c4798();                     /* extern */
s32 func_020cbd18();               /* extern */
M2C_UNK func_020cbe0c();                            /* extern */
M2C_UNK func_020cc1d0();                            /* extern */
s32 func_020cc578();                                /* extern */
s32 func_020cc5b8();                             /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213f2e8;
extern M2C_UNK data_0213f4f8;
extern M2C_UNK data_027e01ac;

void func_020cc818(void) {
    s32 temp_r0;

    if (data_0213ad84 == 0) {
        temp_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
        if (temp_r0 != 0) {
            func_020cc5b8(temp_r0);
            return;
        }
        *(s32 *) 0x04000000 &= ~0xE000;
        if (func_020c0148(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x5A0) == 1) {
            func_020c4798(2);
            return;
        }
        if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x573) < 2U) {
            if (M2C_FIELD(&data_0213ae4c, u16 *, 8) != 1) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x450) = 0U;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x452) = 0U;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x454) = 0U;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x456) = 0U;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x572)  = 0U;
            } else {
                if ((M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0) && ((u32) M2C_FIELD(&data_0213ae4c, u16 *, 6) < 0x78U) &&
                    ((u32) M2C_FIELD(&data_0213ae4c, u16 *, 6) > 0x14U)) {
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x450) =
                        (u16) M2C_FIELD(&data_0213ae4c, u16 *, 4);
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x452) =
                        (u16) M2C_FIELD(&data_0213ae4c, u16 *, 6);
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x572) = 1U;
                }
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x454) = (u16) M2C_FIELD(&data_0213ae4c, u16 *, 4);
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x456) = (u16) M2C_FIELD(&data_0213ae4c, u16 *, 6);
                if (func_020cbd18((s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x452),
                                  M2C_FIELD(&data_0213ae4c, u16 *, 6), 0x10) == 0) {
                    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x572) = 0U;
                }
            }
            func_020cbe0c();
        } else if ((func_020cc578() == 1) && (func_020cc5b8() != 1)) {
            M2C_FIELD(&data_0213b890, s16 *, 0x26)                           = 0x1E;
            M2C_FIELD(&data_0213b890, s8 *, 0x21)                            = 1;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x584) = 2;
            func_02091d4c(0xE79F, &data_0213f4f8, 1, 0x01009080);
            M2C_FIELD(&data_027e01ac, M2C_UNK **, 0x1C) = &data_0213f2e8;
            M2C_FIELD(&data_027e01ac, s16 *, 0x16)      = 0x600;
            M2C_FIELD(&data_027e01ac, s8 *, 0x18)       = 1;
            func_020b82fc(0xB8);
        }
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x572) != 0) {
            func_020cc1d0();
        }
        if (func_020cc5b8() == 1) {
            M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x5A;
            func_020b82fc(0xB7);
            func_020b5540(1);
            M2C_FIELD(&data_0213b890, s8 *, 0x21)                            = 2;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x584) = 1;
            func_02091d4c(0xE79E, &data_0213f4f8, 1, 0x01009080);
            M2C_FIELD(&data_027e01ac, M2C_UNK **, 0x1C) = &data_0213f2e8;
            M2C_FIELD(&data_027e01ac, s16 *, 0x16)      = 0x600;
            M2C_FIELD(&data_027e01ac, s8 *, 0x18)       = 1;
        }
    }
}
