/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
M2C_UNK func_020cffb0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020d02ec(void *, M2C_UNK);             /* extern */

void func_020d00a0(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 3);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, u8 *, 3) = 1U;
            func_020cffb0(arg0, 4);
            func_020b82fc(0xBE);
            return;
        case 1:
            if (M2C_FIELD(arg0, u8 *, 9) == 1) {
                func_020d02ec(arg0, 0);
            }
            return;
    }
}
