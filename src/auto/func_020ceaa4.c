/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020c0148();                             /* extern */
M2C_UNK func_020c4798();                     /* extern */
M2C_UNK func_020ce164();                            /* extern */
M2C_UNK func_020ce1e4();                            /* extern */
M2C_UNK func_020ce36c();                            /* extern */
M2C_UNK func_020ce5d0();                            /* extern */
M2C_UNK func_020ce688();                     /* extern */
s32 func_020ce94c();                                /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020ceaa4(void) {
    if (data_0213ad84 == 0) {
        if (func_020c0148(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x164) == 1) {
            func_020c4798(2);
            return;
        }
        func_020ce1e4();
        func_020ce164();
        func_020ce36c();
        func_020ce5d0();
        func_020ce688(0x10);
        if (func_020ce94c() == 1) {
            M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x1E;
            M2C_FIELD(&data_0213b890, u8 *, 0x21)  = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x21) + 2);
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x146) = 4;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x148) = 0x10;
            if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x13C) <
                (s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x138)) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x147) = 0;
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x147) = 1;
        }
    }
}
