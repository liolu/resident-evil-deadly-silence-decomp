/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02013354(u8, u8, u8, u8);                  /* extern */

u8 func_020134a0(void *arg0) {
    u8 *p;
    s8 cnt;

    p   = (u8 *) arg0;
    cnt = 0;
    goto check;
body:
    if (func_02013354(p[0], p[1], p[2], p[3]) != 0) {
        return (u8) cnt;
    }
    p   = p + 4;
    cnt = (s8) (cnt + 1);
check:
    if (p[1] != 0xFF) {
        goto body;
    }
    return 0xFF;
}
