/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4da4();                 /* extern */
M2C_UNK func_020c4dd8();                         /* extern */
M2C_UNK func_020c83d8();              /* extern */
extern M2C_UNK data_021258f8;
extern M2C_UNK data_02125904;
extern M2C_UNK data_021259a0;
extern M2C_UNK data_02125a00;
extern M2C_UNK data_0213b890;

void func_020c525c(void) {
    s32 temp_r0_2;
    u8 temp_r0;
    u8 temp_r1;

    func_020c4dd8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120);
    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4A);
    if (temp_r0 != 0) {
        func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, ((temp_r0 - 1) * 0xC) + (s32) &data_021259a0);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x128) = 0xA;
        func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
    }
    temp_r1   = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x49);
    temp_r0_2 = temp_r1 & 3;
    if (temp_r0_2 != 0) {
        if (temp_r0_2 == 2) {
            if (temp_r1 & 0x10) {
                func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, (s32) &data_021258f8);
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x128) = 0x7FF;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x130) = 0x68;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x132) = 0x88;
                func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120,
                              M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
            }
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x49) & 0x20) {
                func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, (s32) &data_02125904);
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x128) = 0x7FF;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x130) = 0x68;
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x132) = 0x98;
                func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120,
                              M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
            }
        }
        if ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x49) & 3) != 3) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12E) = 0;
            func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120,
                          ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x49) & 3) * 0xC) +
                              (s32) &data_02125a00);
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x128) = 0x800;
            func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x108);
        }
    }
}
