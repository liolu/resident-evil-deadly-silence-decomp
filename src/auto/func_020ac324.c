/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ac214(M2C_UNK);                     /* extern */
extern void *data_027e000c;

void func_020ac324(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
    if ((temp_r0 == 7) || (temp_r0 == 0x11)) {
        func_020ac214(1);
    }
}
