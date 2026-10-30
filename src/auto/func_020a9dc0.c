/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a9c90();                            /* extern */
M2C_UNK func_020b81b8(u16, void *, M2C_UNK);        /* extern */
extern M2C_UNK data_02121ab8;

void func_020a9dc0(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0x16) {
        func_020a9c90();
        func_020b81b8(((s16 *) &data_02121ab8)[(M2C_FIELD(arg0, u8 *, 0xA) - 7)], arg0 + 0x30, 0);
    }
}
