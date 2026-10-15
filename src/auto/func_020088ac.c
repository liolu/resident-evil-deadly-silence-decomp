/* compiler: 1.2/sp2p3  */
#include "m2c.h"

u8 *func_0200d1f4(void *, M2C_UNK, s32);            /* extern */
extern void *data_02137298;

s32 func_020088ac(M2C_UNK arg0, s32 arg1) {
    u8 *temp_r0;
    void *temp_r0_2;

    temp_r0_2 = M2C_FIELD(data_02137298, void **, 0x1414);
    temp_r0   = func_0200d1f4(temp_r0_2, arg0, M2C_FIELD(M2C_FIELD(temp_r0_2, void **, 0x88), s32 *, 0x20));
    if (temp_r0 == NULL) {
        return -5;
    }
    return *temp_r0 * (arg1 << 9);
}
