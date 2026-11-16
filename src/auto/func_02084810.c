/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02088580();

void func_02084810(u32 arg0, u8 arg1) {
    s32 temp_r0;
    s32 temp_r4;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 *temp_r1;

    if ((arg0 < 0x20U) && ((arg1 < 0x10U) || (arg1 == 0xFF))) {
        temp_r4                  = (s32) func_02088580() + 0xFC;
        temp_r0                  = M2C_FIELD(func_02088580(), s32 *, 0xD8);
        *(u8 *) (temp_r4 + arg0) = arg1;
        temp_r1                  = (u8 *) temp_r0 + (arg0 * 0x10);
        temp_r0_2                = temp_r1[8];
        if ((u32) temp_r0_2 < 0x20U) {
            *(u8 *) (temp_r4 + temp_r0_2) = arg1;
        }
        temp_r0_3 = temp_r1[9];
        if ((u32) temp_r0_3 < 0x20U) {
            *(u8 *) (temp_r4 + temp_r0_3) = arg1;
        }
    }
}
