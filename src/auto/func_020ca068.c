/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020c0148(void *);                          /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
s8 func_020c9ce4();                                 /* extern */
M2C_UNK func_020c9ef0();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020ca068(void) {
    s8 temp_r0;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 3) = (u8) M2C_FIELD(&data_0213b890, u8 *, 0x24);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 1) = 0;
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0) = -1;
    } else if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 6) {
        M2C_FIELD(&data_0213b890, s8 *, 0x1E) = 1;
    }
    if (func_020c0148(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x1C) == 1) {
        func_020c4798(2);
        return;
    }
    temp_r0 = func_020c9ce4();
    if (temp_r0 != -1) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 2) = temp_r0;
        func_020c9ef0();
    }
}
