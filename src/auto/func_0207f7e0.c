/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02082384();                              /* extern */

void func_0207f7e0(void *arg0) {
    s32 temp_r0;
    u8 st;

    st = M2C_FIELD(func_02082384(), u8 *, 1);
    if (st == 1) {
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x1D0);
        if (temp_r0 < 0xC0) {
            M2C_FIELD(arg0, s32 *, 0x1D0) = temp_r0 + 0x40;
            if (M2C_FIELD(arg0, s32 *, 0x1D0) > 0xC0) {
                M2C_FIELD(arg0, s32 *, 0x1D0) = 0xC0;
            }
        }
    } else if (st == 0) {
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x1D0);
        if (temp_r0 > 0) {
            M2C_FIELD(arg0, s32 *, 0x1D0) = temp_r0 - 0x40;
            if (M2C_FIELD(arg0, s32 *, 0x1D0) < 0) {
                M2C_FIELD(arg0, s32 *, 0x1D0) = 0;
            }
        }
    }
}
