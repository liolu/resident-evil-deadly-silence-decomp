/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020147b8(void *);                      /* extern */
M2C_UNK func_02014864();                            /* extern */
M2C_UNK func_02014c0c(void *);                      /* extern */
M2C_UNK func_02090450(u8);                          /* extern */

void func_020148b4(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x19);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02014864(arg0);
        /* fallthrough */
        case 1:
            if (M2C_FIELD(arg0, u8 *, 0x12) != 0xFF) {
                func_020147b8(arg0);
                return;
            }
        default:
            func_02090450(M2C_FIELD(arg0, u8 *, 0x17));
            func_02014c0c(arg0);
            return;
    }
}
