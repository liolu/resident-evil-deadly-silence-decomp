/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020b6820(u16);                         /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d40ac(void) {
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) >= 0x320) {
        func_020b5540(1);
        func_020c4798(2);
        func_020b6820(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x40));
        return;
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x21)                            = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x21) - 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x22) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x28) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x3E) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x25)                            = 0;
    func_020b6820(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x42));
}
