/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020feda8(s32 *);                           /* extern */
M2C_UNK func_020feef0(s32 *, s32 *, s32 *);         /* extern */
M2C_UNK func_0211851c(s32, M2C_UNK);                /* extern */

void func_0208ac10(s16 *arg0, s16 *arg1) {
    s32 a[3];
    s32 b[3];
    s32 zero;
    s32 y;
    s32 x;

    zero = 0;
    y    = (s32) arg0[1] << 12;
    x    = (s32) arg0[0] << 12;
    a[0] = x;
    a[1] = y;
    a[2] = zero;
    y    = (s32) arg1[1] << 12;
    x    = (s32) arg1[0] << 12;
    b[0] = x;
    b[1] = y;
    b[2] = zero;
    func_020feef0(b, a, a);
    func_0211851c(func_020feda8(a), 0x1000);
}
