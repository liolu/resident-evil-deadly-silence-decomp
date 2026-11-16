/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014dac(s32, u8); /* extern */

void func_02088204(s32 arg0, s32 arg1) {
    s32 i;
    u8 *p;

    i = 0;
    while (i < 4) {
        p = func_02014dac(2, (u8) i);
        if ((p == NULL) || (p[0x16] == 2)) {
            break;
        }
        p[0x16]           = 1;
        p[0x17]           = (u8) arg1;
        *(u16 *) &p[0x1C] = (u16) arg0;
        i += 1;
    }
}
