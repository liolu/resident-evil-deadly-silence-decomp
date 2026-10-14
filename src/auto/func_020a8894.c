/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_01ffd214(M2C_UNK, M2C_UNK);
M2C_UNK func_01ffd2c4(M2C_UNK, M2C_UNK);
M2C_UNK func_020a5b0c(M2C_UNK);
M2C_UNK func_020a9b08(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020ac214(M2C_UNK);
M2C_UNK func_020ad9a8(void);

extern M2C_UNK data_0213ad98;
extern s32 data_027e0024;

void func_020a8894(s32 arg0) {
    s32 temp_r5;

    if ((M2C_FIELD(arg0, u8 *, 0x93) != 0) && (M2C_FIELD(&data_0213ad98, u16 *, 0x22) & 0x40)) {
        func_020a5b0c(arg0);
    }
    temp_r5 = func_020ad9a8() << 5;
    data_027e0024 = temp_r5 + 0xF0;
    if (func_01ffd2c4(M2C_FIELD(arg0, s32 *, 0x9C) + 0x30, 0x200) == 0) {
        data_027e0024 = temp_r5 + 0xC0;
    }
    func_01ffd214(M2C_FIELD(arg0, s32 *, 0x9C) + 0x30, (s32) (s16) data_027e0024);
    if (func_01ffd2c4(M2C_FIELD(arg0, s32 *, 0x9C) + 0x30, 0x20) == 0) {
        M2C_FIELD(arg0, s8 *, 0x92) = 0x13;
        M2C_FIELD(arg0, u8 *, 0x93) = 0U;
    } else if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s16 *, 0xA6) = 1;
        func_020ac214(1);
    }
    func_020a9b08(arg0, 0, 0x400);
}
