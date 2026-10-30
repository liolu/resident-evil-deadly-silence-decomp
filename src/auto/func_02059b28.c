/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_020ad9a8();                                 /* extern */
extern M2C_UNK data_0211d560;
extern M2C_UNK data_02144c04;

u8 func_02059b28(void *arg0) {
    u8 temp_r1;

    if (arg0 == &data_02144c04) {
        return func_020ad9a8();
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 9);
    if ((u32) temp_r1 < 0x20U) {
        return 2U;
    }
    return *((u8 *) ((s8 *) &data_0211d560 + (temp_r1 - 0x20)));
}
