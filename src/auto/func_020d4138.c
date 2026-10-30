/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020c0148();                             /* extern */
M2C_UNK func_020c4798();                     /* extern */
M2C_UNK func_020d3e34();                            /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020d4138(void) {
    s32 temp_r0;

    if (data_0213ad84 == 0) {
        if (func_020c0148(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x5C) == 1) {
            func_020c4798(2);
            return;
        }
        func_020d3e34();
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) =
            (s32) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) +
                   M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x38));
        temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34);
        if (temp_r0 > 0x3E8) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) = 0x3E8;
            return;
        }
        if (temp_r0 < 0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x34) = 0;
        }
    }
}
