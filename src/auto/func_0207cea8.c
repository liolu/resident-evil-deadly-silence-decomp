/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02088580();                                /* extern */

s32 func_0207cea8(void) {
    s32 temp_r0;
    u8 var_ip;
    u8 temp_r2;
    void *temp_r3;

    temp_r0 = func_02088580();
    for (var_ip = 0; var_ip < 0x10; var_ip++) {
        temp_r3 = M2C_FIELD(((u32) var_ip * 0x1E8) + temp_r0, void **, 0x130);
        if (temp_r3 != NULL) {
            temp_r2 = M2C_FIELD(temp_r3, u8 *, 9);
            if ((temp_r2 == 0) || ((u8) (temp_r2 + 0xFB) <= 2)) {
                if (M2C_FIELD(temp_r3, u8 *, 0x91) == 0xC) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
