/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020adad0(s32);                         /* extern */
s32 func_020adcf8(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02144cc0;

void func_020a65e4(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, u8 *, 0x93) = 1U;
            M2C_FIELD(arg0, s8 *, 0x98) = 3;
            M2C_FIELD(arg0, s8 *, 0xA1) = 4;
            func_020adad0(0x8008);
        /* fallthrough */
        case 1:
            if (func_020adcf8(0, 0x400) != 0) {
                if (*M2C_FIELD(&data_02144cc0, u8 **, 0xDC) == 0xD) {
                    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x100);
                } else {
                    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x800);
                }
                M2C_FIELD(arg0, u8 *, 0x93)            = 2U;
                M2C_FIELD(arg0, s8 *, 0x98)            = 0;
                M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x40);
                M2C_FIELD(arg0, u8 *, 0xC0)            = (u8) (M2C_FIELD(arg0, u8 *, 0xC0) & ~0x80);
                return;
            }
            return;
        case 2:
            if (func_020adcf8(2, 0x400) != 0) {
                M2C_FIELD(arg0, s8 *, 0x91) = 0;
                M2C_FIELD(arg0, s8 *, 0x92) = 0;
                M2C_FIELD(arg0, u8 *, 0x93) = 0U;
            }
            break;
    }
}
