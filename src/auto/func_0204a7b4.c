/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void *func_02053c74();

void func_0204a7b4(void *arg0, s32 arg1, s32 arg2) {
    void *p = arg0;
    s32 n   = arg2;

    goto cond;
loop:
    *((u8 *) p + 8) &= ~arg1;
    p = func_02053c74();
    n = (u8) (n - 1);
cond:
    if (n != 0) {
        goto loop;
    }
}
