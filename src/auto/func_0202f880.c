/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0202c120();                            /* extern */
M2C_UNK func_020304c8(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_0202f880(void) {
    u8 temp_r0;

    M2C_FIELD(data_027e000c, s8 *, 0xA1)  = 0x1A;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    if ((u32) M2C_FIELD(data_027e000c, u8 *, 0xA2) < 3U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0xFA;
    }
    func_0202c120();
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
    if ((temp_r0 == 0xD) || (temp_r0 == 0x17)) {
        func_020304c8(4, 0);
    }
}
