/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_0200d65c();
extern void func_020b7de8(s32);

void func_020b7db8(void) {
    s32 i;

    func_0200d65c(0);
    i = 0;
    goto check;
body:
    func_020b7de8(i);
    i++;
check:
    if (i < 5) {
        goto body;
    }
}
