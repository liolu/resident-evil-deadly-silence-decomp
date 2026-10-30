/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0208fe14();                              /* extern */

void func_0209018c(s32 arg0, s32 arg1) {
    void *temp_r0;

    temp_r0 = func_0208fe14();
    if (temp_r0 != NULL) {
        if (arg1 != 0) {
            M2C_FIELD(temp_r0, u8 *, 1) = (u8) (M2C_FIELD(temp_r0, u8 *, 1) & ~0x10);
            return;
        }
        M2C_FIELD(temp_r0, u8 *, 1) = (u8) (M2C_FIELD(temp_r0, u8 *, 1) | 0x10);
    }
}
