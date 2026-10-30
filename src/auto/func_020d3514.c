/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d318c();                            /* extern */
M2C_UNK func_020d31bc(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d3514(void) {
    if ((s32) ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xE0) >> 0xC) > -0x30) {
        func_020d31bc(0x18000);
        func_020d318c();
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x50) = 0xC0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xE0) = 0xC0000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x4E) =
        (u16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x4E) + 8);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xE0) =
        (s32) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xE0) + 0x8000);
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 2;
}
