/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02051218();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern void *data_027e000c;

void func_020517d4(void) {
    func_02051218();
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        func_020559cc(data_027e000c, 5);
    }
}
