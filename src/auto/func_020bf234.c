/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020bedcc();                            /* extern */
M2C_UNK func_020beec0();                            /* extern */
M2C_UNK func_020bf048(M2C_UNK);                     /* extern */
s32 func_020bf060(M2C_UNK, M2C_UNK);                /* extern */
s32 func_020bf0a0(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_0213b890;

void func_020bf234(void) {
    s8 temp_r0;

    func_020beec0();
    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x16);
    switch (temp_r0) {                              /* irregular */
        case 1:
            if (func_020bf0a0(0xE4, 0x32) == 1) {
                func_020bf048(1);
                func_020bedcc();
            }
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x18) = 1;
            return;
        case 0:
            if (func_020bf060(-0xD6, 0x32) == 1) {
                func_020bf048(1);
                func_020bedcc();
            }
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x17) = 1;
            M2C_FIELD(&data_0213b890, s8 *, 0x24)                           = 0;
            return;
    }
}
