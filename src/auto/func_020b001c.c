#include "m2c.h"

void func_020b001c(s8 *arg0, s8 *arg1) {
    s8 *d = arg0;
    s8 *s = arg1;
    s8 c;
    goto check;
loop:
    c    = *s++;
    *d++ = c;
check:
    if (*s != 0) {
        goto loop;
    }
}
