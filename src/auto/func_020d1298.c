/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d0cbc();                            /* extern */
M2C_UNK func_020d135c(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d1298(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x42);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x40) = 1;
            func_020d0cbc();
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x42) = 1U;
            return;
        case 1:
            if (*M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20), s32 **, 0x10) == 0xD000) {
                func_020d135c(0);
            }
            return;
    }
}
