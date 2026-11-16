/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

void func_0208fdbc(void *arg0) {
    s32 var_r4;
    s32 temp_lr;

    var_r4 = M2C_FIELD(arg0, u8 *, 3) & 0xF;
    goto cond;
loop:
    temp_lr                   = (s32) arg0 + (var_r4 * 0x1C);
    *(T12 *) (temp_lr + 4)    = *(T12 *) (temp_lr - 0x18);
    *(T12 *) (temp_lr + 0x10) = *(T12 *) (temp_lr - 0xC);
    var_r4 -= 1;
cond:
    if (var_r4 > 0) {
        goto loop;
    }
}
