/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02014dac(s32, u8);

void func_020881c0(void) {
    s32 i;
    void *p;
    s32 v;

    i = 0;
    v = 2;
    goto cond;
body:
    p = func_02014dac(v, (u8) i);
    if (p == NULL) {
        return;
    }
    ((u8 *) p)[0x16] = v;
    i++;
cond:
    if (i < 4) {
        goto body;
    }
}
