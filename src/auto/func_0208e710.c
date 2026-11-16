/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02003a0c(s32);
void func_020039b8(s32, s32);

void func_0208e710(s32 arg0) {
    s32 base;
    s32 i;
    s32 cur;

    if (arg0 != 0) {
        base = 0;
    } else {
        base = 4;
    }
    for (i = 0; i < 4; i++) {
        cur = base + i;
        func_02003a0c(cur);
        func_020039b8(cur, 16);
    }
}
