/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020140f0(void *);                      /* extern */
M2C_UNK func_02014430();                            /* extern */
M2C_UNK func_02014c0c(void *);                      /* extern */
s32 func_02088428();                                /* extern */

void func_02014524(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x19);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_02014430(arg0);
            return;
        case 1:
            if (M2C_FIELD(arg0, u8 *, 0x12) != 0xFF) {
                if (func_02088428() == 0) {
                    func_020140f0(arg0);
                    return;
                }
            } else {
                default:
                    func_02014c0c(arg0);
                    return;
            }
            break;
    }
}
