/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020beee8();                            /* extern */
M2C_UNK func_020bf048(M2C_UNK);                     /* extern */
s32 func_020bf060(M2C_UNK, M2C_UNK);                /* extern */
s32 func_020bf0a0(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_027e01ac;

void func_020bf4f0(void) {
    s8 temp_r0;

    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* switch 1; irregular */
        case 0:                                         /* switch 1 */
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x16) == 1) {
                M2C_FIELD(&data_027e01ac, s16 *, 0x20) = -0xD6;
            } else {
                M2C_FIELD(&data_027e01ac, s16 *, 0x20) = 0xE4;
            }
            func_020beee8();
            M2C_FIELD(&data_0213b890, u8 *, 0x22) = 1U;
            return;
        case 1:                                         /* switch 1 */
            temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x16);
            switch (temp_r0) {                          /* switch 2; irregular */
                case 1:                                     /* switch 2 */
                    if (func_020bf0a0(0, 0x32) == 1) {
                        M2C_FIELD(&data_0213b890, u8 *, 0x1D) =
                            (u8) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x14);
                        func_020bf048(2);
                        return;
                    }
                    return;
                case 0:                                     /* switch 2 */
                    if (func_020bf060(0, 0x32) == 1) {
                        M2C_FIELD(&data_0213b890, u8 *, 0x1D) =
                            (u8) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x14);
                        func_020bf048(2);
                    }
                    break;
            }
            break;
    }
}
