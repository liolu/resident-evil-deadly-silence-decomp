/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void *func_02088580(void);

void *func_0208531c(s32 arg0) {
    u8 *base;
    u8 i;
    s32 off;
    u8 *cell;
    void *p;

    base = func_02088580();
    i    = 0;
    goto check;
body:
    off  = i * 0x1E8;
    cell = base + off;
    p    = *(void **) (cell + 0x130);
    if (p != NULL && arg0 == ((u8 *) p)[9]) {
        return (base + 0x130) + off;
    }
    i = i + 1;
check:
    if (i < 16) {
        goto body;
    }
    return NULL;
}
