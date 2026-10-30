/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5550();                            /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020f8438(s32, u16);                    /* extern */
M2C_UNK func_020f86e8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_0214e5c0;

void func_020d1fc0(void) {
    func_020b5550();
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xE8) = (u16) M2C_FIELD(&data_0214e5c0, u16 *, 0x76);
    func_020f8438(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2C), s32 *, 0xC),
                  M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xE8));
    func_020f86e8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2C), s32 *, 0xC), 1, 0x40);
    if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0) {
        func_020c4798(3);
    }
}
