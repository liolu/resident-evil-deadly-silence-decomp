/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_020b80f4(u8, s32);
extern M2C_UNK func_020b83e0(s32);
extern M2C_UNK func_020b86cc(s32);

void func_020b8374(void) {
    s32 i;
    s32 n;

    func_020b86cc(0x318);
    i = 0;
    n = -1;
loop_a:
    if (i != 2) {
        func_020b80f4((u8) i, n);
    }
    i += 1;
    if ((u32) i <= 6U) {
        goto loop_a;
    }
    n = 2;
    goto check;
body:
    func_020b83e0(n);
    n += 1;
check:
    if (n < 0x10) {
        goto body;
    }
    func_020b86cc(0x325);
}
