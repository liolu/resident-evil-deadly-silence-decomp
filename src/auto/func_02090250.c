/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0208fe14();                              /* extern */

void func_02090250(s32 arg0, u32 arg1) {
    u8 temp_r1;
    void *temp_r0;

    temp_r0 = func_0208fe14();
    if (temp_r0 != NULL) {
        temp_r1 = M2C_FIELD(temp_r0, u8 *, 3);
        if (arg1 <= (u32) temp_r1) {
            M2C_FIELD(temp_r0, u8 *, 3) = (u8) (temp_r1 & 0xF);
            M2C_FIELD(temp_r0, u8 *, 3) = (u8) (M2C_FIELD(temp_r0, u8 *, 3) | (arg1 * 0x10));
        }
    }
}
