/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a7184();                            /* extern */
M2C_UNK func_020a76e4(void *);                      /* extern */

void func_020a7750(void *arg0) {
    func_020a7184();
    if ((u32) M2C_FIELD(arg0, u8 *, 0x92) <= 0x11U) {
        func_020a76e4(arg0);
    }
}
