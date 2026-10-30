/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02091af8(void *);                      /* extern */
extern M2C_UNK data_021375ac;

void func_02087f98(void *arg0) {
    s32 temp_r1;
    u8 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u8 *, 1);
    temp_r1 = temp_r2 & 0xE0;
    switch (temp_r1) {                              /* irregular */
        case 0x80:
            M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AF) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AF) + 1);
            if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A8) == NULL) {
                M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A8) = arg0;
            }
            return;
        case 0x20:
            M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AE) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AE) + 1);
        /* fallthrough */
        case 0x40:
            if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A4) == NULL) {
                M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A4) = arg0;
            }
            return;
        default:
            if (temp_r2 == 0) {
                if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x59C) == NULL) {
                    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x59C) = arg0;
                    func_02091af8(M2C_FIELD(&data_021375ac, void **, 0x64) + 0x4C8);
                    return;
                }
            } else {
                M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AD) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x5AD) + 1);
                if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A0) == NULL) {
                    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x5A0) = arg0;
                }
                return;
            }
            break;
    }
}
