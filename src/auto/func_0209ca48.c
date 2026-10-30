/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_020d8e0c(M2C_UNK);                       /* extern */
M2C_UNK func_020d914c();                            /* extern */
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213caa0;
extern M2C_UNK func_02093b80;

s32 func_0209ca48(void) {
    void *temp_r0;

    if (((u32) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F60) << 0x1A) >> 0x1F) == 0) {
        temp_r0 = func_020d8e0c(0);
        if ((temp_r0 != NULL) && (M2C_FIELD(temp_r0, u8 *, 0x22) == M2C_FIELD(&data_0213caa0, u8 *, 0x706))) {
            func_020d914c();
            M2C_FIELD(&data_0213b2b4, M2C_UNK **, 0xA8) = &func_02093b80;
            return 1;
        }
    }
    return 0;
}
