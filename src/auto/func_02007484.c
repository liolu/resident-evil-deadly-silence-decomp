/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0210516c(void *, s32, M2C_UNK, M2C_UNK *, s32); /* extern */
extern void *data_02137298;
extern M2C_UNK func_02007418;

void func_02007484(void) {
    if (M2C_FIELD(data_02137298, u8 *, 0x3EA9) == 1) {
        func_0210516c(data_02137298 + 0x3EC0, 0x3FEC4, 0, &func_02007418, -1);
    }
}
