/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02020674(void *);                      /* extern */
M2C_UNK func_020206a4(void *);                      /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */

void func_02020720(void *arg0) {
    func_02075738(1, 0x100);
    if (M2C_FIELD(arg0, u8 *, 0x92) == 0) {
        func_020206a4(arg0);
        return;
    }
    func_02020674(arg0);
}
