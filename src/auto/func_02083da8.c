/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208358c(void **, M2C_UNK);            /* extern */
void *func_02084984();                              /* extern */
M2C_UNK func_020849ac();                            /* extern */

s32 func_02083da8(void **arg0) {
    void *temp_r0;

    func_020849ac();
    temp_r0 = func_02084984();
    if (temp_r0 == NULL) {
        func_0208358c(arg0, 2);
        return 0;
    }
    if (M2C_FIELD(temp_r0, u8 *, 5) != 0xFF) {
        func_0208358c(arg0, 0xE);
        M2C_FIELD(*arg0, u8 *, 0x93) = (u8) M2C_FIELD(temp_r0, u8 *, 5);
        return 1;
    }
    func_0208358c(arg0, 2);
    return 0;
}
