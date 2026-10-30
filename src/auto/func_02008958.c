/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0200d1f4(void *, M2C_UNK, s32);          /* extern */
extern void *data_02137298;

s32 func_02008958(M2C_UNK arg0) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0_2 = M2C_FIELD(data_02137298, void **, 0x1414);
    temp_r0   = func_0200d1f4(temp_r0_2, arg0, M2C_FIELD(M2C_FIELD(temp_r0_2, void **, 0x88), s32 *, 0x24));
    if (temp_r0 == NULL) {
        return -1;
    }
    return M2C_FIELD(((M2C_FIELD(temp_r0, u8 *, 6) * 0x10C) + (s32) data_02137298), s32 *, 0x3A64);
}
