/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020ce5d0();                            /* extern */
M2C_UNK func_020ce688(s8);                          /* extern */
s8 func_0211851c(s8, M2C_UNK);                      /* extern */
extern M2C_UNK data_0213b890;

void func_020ce97c(void) {
    s8 temp_r0;
    void *temp_r4;

    func_020ce5d0();
    M2C_FIELD((M2C_FIELD(&data_0213b890, void **, 0x4C) + M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x147)),
              s8 *, 0x140) = 0xE;
    M2C_FIELD(
        (M2C_FIELD(&data_0213b890, void **, 0x4C) + (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x147) ^ 1)),
        s8 *, 0x140) = (s8) (0xE - (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x146) * 2));
    func_020ce688(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x148));
    if ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x13C) ==
         M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x138)) ||
        (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x145) != 0)) {
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x146) == 0) {
            func_020b82fc(0xDA);
            M2C_FIELD(&data_0213b890, u8 *, 0x21) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x21) - 1);
            return;
        }
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x147) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x147) ^ 1);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x146) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x146) - 1);
        temp_r4 = M2C_FIELD(&data_0213b890, void **, 0x4C);
        temp_r0 = M2C_FIELD(temp_r4, s8 *, 0x148);
        if (temp_r0 != 4) {
            M2C_FIELD(temp_r4, s8 *, 0x148) = func_0211851c(temp_r0, 2);
        }
    }
}
