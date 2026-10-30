/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02076e50();                            /* extern */

void func_0208d61c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x90) != 4) {
        M2C_FIELD(arg0, s8 *, 0xB) = 0;
        func_02076e50(arg0);
        M2C_FIELD(arg0, u8 *, 0x90) = 4U;
    }
}
