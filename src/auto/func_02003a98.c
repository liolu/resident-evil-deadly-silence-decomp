/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020039b8(s32, M2C_UNK);
M2C_UNK func_02003a0c(s32);

void func_02003a98(void) {
    s32 i;

    i = 0;
    goto cond;
loop:
    func_020039b8(i, 2);
    func_02003a0c(i);
    i += 1;
cond:
    if (i <= 3) {
        goto loop;
    }
}
