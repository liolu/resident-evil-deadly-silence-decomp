/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020cd264();                            /* extern */
s32 func_020cd71c();                                /* extern */
extern M2C_UNK data_0213b890;

void func_020cd978(void) {
    s32 *temp_r2;

    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
    *temp_r2 += 0x1000;
    if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x4000) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0;
    }
    if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x7000) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10)    = 0x7FFF;
        *M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) = 0;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x13) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x13) - 1);
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x13) == 0) {
            M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x1E;
        }
        func_020cd264();
        func_020b82fc(0xBC);
        if (func_020cd71c() != 0) {
            func_020c4798(2);
        }
        M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
    }
}
