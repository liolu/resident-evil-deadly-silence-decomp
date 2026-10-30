/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014e00(M2C_UNK);                       /* extern */
M2C_UNK func_0209fbf0(M2C_UNK);                     /* extern */
extern M2C_UNK data_027e009c;

void func_020a9c18(void) {
    void *temp_r0;

    temp_r0 = func_02014e00(0);
    if (temp_r0 != NULL) {
        func_0209fbf0(7);
        M2C_FIELD(temp_r0, s32 *, 0x20) = (s32) M2C_FIELD(&data_027e009c, s32 *, 0x14);
        M2C_FIELD(temp_r0, s32 *, 0x24) = (s32) M2C_FIELD(&data_027e009c, s32 *, 0x18);
        M2C_FIELD(temp_r0, s32 *, 0x28) = (s32) M2C_FIELD(&data_027e009c, s32 *, 0x1C);
    }
}
