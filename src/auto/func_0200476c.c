/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_0200464c(s32, s32, void *); /* extern */
s32 func_020049e8(void *, void *);   /* extern */
s32 func_0200496c(void *);           /* extern */

s32 func_0200476c(void *arg0, s32 arg1) {
    u8 sp0[36];
    s32 var_r4;

    var_r4 = -1;
    if ((func_0200464c(arg1 + *(s32 *) ((u8 *) arg0 + 0x14), 0x20, sp0) != 0) && (func_020049e8(arg0, sp0) != 0) &&
        (func_0200496c(sp0) != 0)) {
        var_r4 = *(u16 *) &sp0[30];
    }
    return var_r4;
}
