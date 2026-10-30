/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0202c120();                            /* extern */
M2C_UNK func_020304c8(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_0202f8f4(void) {
    u8 temp_r0;

    M2C_FIELD(data_027e000c, s8 *, 0xA1)  = 0x1B;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    func_0202c120();
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
    if ((temp_r0 == 0x32) || (temp_r0 == 0x24)) {
        func_020304c8(7, 0);
    }
    if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0x4B) {
        func_020304c8(4, 0);
    }
}
