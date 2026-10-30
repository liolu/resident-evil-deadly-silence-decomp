/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020d1614(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d1450(void) {
    s32 *temp_r2;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x45);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x45) = 1U;
            M2C_FIELD(&data_0213b890, s8 *, 0x1C)                           = 2;
            func_020b82fc(0xCC);
            return;
        case 1:
            temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10);
            if (*temp_r2 == 0x4E000) {
                *temp_r2 = 0x3C000;
                func_020d1614(1);
            }
            return;
    }
}
