/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020cefd0();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020cf438(void) {
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11E) !=
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x11C)) {
        func_020cefd0();
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11D) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11B) =
            (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11B) + 1);
        if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11B) >= 6U) {
            func_020b5540(1);
            M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x1E;
            M2C_FIELD(&data_0213b890, s8 *, 0x21)  = 4;
            return;
        }
        goto block_6;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x11B) = 0U;
block_6:
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 0;
}
