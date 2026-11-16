/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 *func_02088580(void);

void func_020850d8(void *arg0) {
    u8 var_r6;
    u32 *temp_r5;
    s32 temp_r4;
    u8 *base;
    u8 *p;
    s32 *q;
    u32 var_ip;

    temp_r5 = M2C_FIELD(arg0, u32 **, 0xB0);
    temp_r4 = M2C_FIELD(arg0, s32 *, 4);
    var_r6  = 0x1F;
    base    = func_02088580();
    var_ip  = 0;
    while (var_ip < 0x10U) {
        p = base + var_ip * 0x1E8;
        q = M2C_FIELD(p, s32 **, 0x130);
        if ((q != NULL) && ((*q + 0x20) == temp_r4)) {
            var_r6 = M2C_FIELD(p, u8 *, 0x147);
            break;
        }
        var_ip = (u8) (var_ip + 1);
    }
    temp_r5[3] = (temp_r5[3] & ~0x1F0000) | (var_r6 << 0x10);
}
