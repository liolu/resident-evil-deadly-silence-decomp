/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020520c0();                            /* extern */
extern void *data_027e000c;

void func_02052a80(void) {
    func_020520c0();
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x20);
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    }
}
