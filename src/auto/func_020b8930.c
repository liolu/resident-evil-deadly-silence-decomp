/* compiler: 1.2/sp2p3 */
#include "m2c.h"

u8 func_020b8930(u32 arg0) {
    u8 i;

    i = 0;
    goto cond;
body:
    if ((1U << i) == arg0) {
        return i;
    }
    i = i + 1;
cond:
    if (i < 0x10) {
        goto body;
    }
    return 0;
}
