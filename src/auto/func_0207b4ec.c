/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207b204(void **);                     /* extern */
s32 func_0207b240(void **);                         /* extern */
M2C_UNK func_0207b338();                            /* extern */

void func_0207b4ec(void **arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(*arg0, u8 *, 0x90);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_0207b338(arg0);
        /* fallthrough */
        case 1:
            if (func_0207b240(arg0) == 0) {
                case 2:
                    func_0207b204(arg0);
            }
            return;
    }
}
